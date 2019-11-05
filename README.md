# UA NBU BankId response decoder

## Usage

```
require 'base64'
require 'json'
require 'nbu_bankid_decoder'

private_key = File.binread(options.private_key_path)
my_cert = File.binread(options.public_key_path)
bank_cert = Base64::decode64(response['cert'])
customer_crypto = Base64::decode64(response['customerCrypto'])
json_string = NbuBankIdDecoder.decrypt_response(customer_crypto, private_key, my_cert, bank_cert)
data = JSON.parse(json_string)
```

Code uses implementation from https://github.com/privat-it/cryptonite

## BankID API

- https://id.bank.gov.ua/assets/docs/Specification_BankID_NBU_Portal_v4.pdf
- https://zakon.rada.gov.ua/laws/file/text/62/f394156n26.doc

```
POST https://id.bank.gov.ua/v1/bank/resource/client HTTP/1.1
Authorization: Bearer access_token
Content-Type: application/json
{
  "type":"physical",
  "cert":"dEBIGx1pdL6dt1ngaOEfPvt/ik9eUpDuz90rm/Vk23v+FtiKJEvGnuea9FGjvBMGlFZS4zhg2IYIHGOhlBVYrZcez6udotjZlCLGZ7zwPuFo0XypKDQj5qpR7w0rFFZNjcPH3JW2IzEUv",
  "fields":["firstName","middleName","lastName","phone","inn","clId","clIdText","birthDay"]
}
```

Response is **encryptedContent** as defined by https://tools.ietf.org/html/rfc5652
