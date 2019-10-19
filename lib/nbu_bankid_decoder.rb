require 'openssl'
require 'nbu_bankid_decoder/asn_tools'
require 'nbu_bankid_decoder/nbu_bankid_decoder'
module NbuBankIdDecoder
  VERSION = "0.0.1"

  class InitialEnvelope
    def initialize(bindata)
      @asn = OpenSSL::ASN1.decode(bindata)
    end

    def encrypted_key
      @asn.value[1].value[0].value[1].value[0].value[3].value
    end

    def iv
      @asn.value[1].value[0].value[2].value[1].value[1].value[0].value
    end

    def encrypted_data
      @asn.value[1].value[0].value[2].value[2].value
    end
  end

  class SignedEnvelope
    def initialize(bindata)
      @asn = OpenSSL::ASN1.decode(bindata)
    end

    def data
      @asn.value[1].value[0].value[2].value[1].value[0].value
    end
  end

  module_function

  def decrypt_response(customer_crypto, private_key)
    envelope = InitialEnvelope.new(customer_crypto)

    data = envelope.encrypted_data
    iv = envelope.iv
    key = private_key.private_decrypt(envelope.encrypted_key)

    decrypted = NbuBankIdDecoder.gost28147_ctr_decode(data, key, iv)

    SignedEnvelope.new(decrypted).data
  end
end
