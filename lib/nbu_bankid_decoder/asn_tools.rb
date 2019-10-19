require 'openssl'
module NbuBankIdDecoder
  module AsnTools
    # Convert ASN.1 to loose XML to understand structure
    #
    #     puts AsnToXml.new(File.binread(ARGV[0])).to_xml
    #
    class AsnToXml
      def initialize(bindata)
        @asn = OpenSSL::ASN1.decode(bindata)
      end

      def trimm(s)
        has_bin = s.split(//).any?{|x| x.ord < 32 || "<>&".include?(x) || x.ord == 0xa0 && s[0] != '{' }
        if has_bin
          "HEX:"+s.unpack("H*").first
        else
          s
        end
      end

      def tag(name, endtag = false)
        "<"+(endtag ? "/" : "") + name.sub(/^OpenSSL::ASN1::/,'')+">"
      end

      def trav(asn, out)
        out << tag(asn.class.to_s)
        if asn.value.is_a?(Array)
          asn.value.each do |v|
            trav(v, out)
          end
        else
          out << trimm(asn.value.to_s)
        end
        out << tag(asn.class.to_s, true)
      end

      def to_xml
        out = '<?xml version="1.0" encoding="utf-8"?>'
        trav(@asn, out)
        out
      end
    end

    # Dumps data as value path:
    #
    #     asn:
    #       asn.value[0].value: pkcs7-envelopedData
    #       asn.value[1]:
    #         asn.value[1].value[0]:
    #           asn.value[1].value[0].value[0].value: 2
    #           asn.value[1].value[0].value[1]:
    #             asn.value[1].value[0].value[1].value[0]:
    #               asn.value[1].value[0].value[1].value[0].value[0].value: 2
    #               asn.value[1].value[0].value[1].value[0].value[1].value: HEX:c35e86996709293916a881dd98567867bdd9244c
    #               asn.value[1].value[0].value[1].value[0].value[2]:
    #                 asn.value[1].value[0].value[1].value[0].value[2].value[0].value: rsaEncryption
    #                 asn.value[1].value[0].value[1].value[0].value[2].value[1].value:
    #               asn.value[1].value[0].value[1].value[0].value[3].value: HEX:876f8...
    #
    class AsnToValuePath
      def initialize(bindata)
        @asn = OpenSSL::ASN1.decode(bindata)
      end

      def trimm(s)
        has_bin = s.split(//).any?{|x| x.ord < 32 || "<>&".include?(x) || x.ord == 0xa0 && s[0] != '{' }
        if has_bin
          "HEX:"+s.unpack("H*").first
        else
          s
        end
      end

      def trav(asn, out, path, level )
        if asn.value.is_a?(Array)
          out << ("  " * level + path + ":\n")
          asn.value.each_with_index do |v, idx|
            trav(v, out, path + ".value[#{idx}]", level+1)
          end
        else
          out << ("  " * level + path)
          out << ".value: "+trimm(asn.value.to_s)+"\n"
        end
      end

      def to_text
        out = ''
        trav(@asn, out, 'asn', 0)
        out
      end
    end
  end
end
