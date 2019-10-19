# UA NBU BankId response decoder

## Usage

```
require 'base64'
require 'json'
require 'nbu_bankid_decoder'

private_key = OpenSSL::PKey::RSA.new(File.read(options.private_key_path))
customer_crypto = Base64::decode64(response['customerCrypto'])
json_string = NbuBankIdDecoder.decrypt_response(customer_crypto, private_key)
data = JSON.parse(json_string)
```

Code uses GOST28147 implementation from https://github.com/privat-it/cryptonite

## API docs and explanation

https://testid.bank.gov.ua/assets/docs/Specification_BankID_NBU_Portal_v4.pdf

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

UA docs:

> Посилений сертифікат шифрування передається в атрибуті "cert" у форматі base64.
> Порядок шифрування анкети визначено в пункті 3.3. цієї специфікації взаємодії.

Google translate:

> Enhanced encryption certificate is passed in the base64 "cert" attribute.
> The encryption procedure for the questionnaire is defined in item 3.3. of this interaction specification.

**Clarification**: "cert" is your Base64 certificate registered for BankID.
When loading from PEM, just strip BEGIN/END cert lines and new line chars:

```ruby
cert = File.read(options.cert_path)
cert.gsub!("-----BEGIN CERTIFICATE-----", "")
cert.gsub!("-----END CERTIFICATE-----", "")
cert.gsub!("\n", "")
cert
```

UA docs:

> Відповідь надається у вигляді Json-об’єкта, в якому банк передає через ц. в.
> BankID НБУ свій посилений сертифікат шифрування та цифровий конверт, що
> містить зашифровані й підписані персональні дані. Посилений сертифікат
> шифрування банку міститься в атрибуті "cert" у форматі base64. Цифровий
> конверт із даними про користувача в підписаному та зашифрованому вигляді
> разом із зашифрованим ключем шифрування даних містяться в атрибуті
> "customerCrypto" у форматі base64.
> Розшифрування підписаних персональних даних користувача відбувається
> згідно з вимогами до форматів криптографічних повідомлень, визначених
> наказом Адміністрації Державної служби спеціального зв'язку та захисту
> інформації України від 18.12.2012 № 739 (http://zakon3.rada.gov.ua/laws/show/z0108-13) (далі – Вимоги). 
> Узгодження ключів за замовчуванням здійснюється з
> використанням статичного механізму. Якщо параметри криптографічного
> алгоритму статичної ключової пари відправника не еквівалентні параметрам
> криптографічного алгоритму статичної ключової пари одержувача, повинен
> здійснюватися перехід до застосування динамічного механізму узгодження
> ключів. Засоби криптографічного захисту інформації відправника та
> одержувача мають підтримувати криптографічні алгоритми, визначені цими
> Вимогами.

Google translate:

> The answer is given in the form of a Json object, in which the bank transfers through. in.
> BankID NBU its enhanced encryption certificate and digital envelope
> contains encrypted and signed personal information. Enhanced certificate
> Bank encryption is contained in the base64 "cert" attribute. Digital
> signed and encrypted user envelope
> along with the encrypted data encryption key are contained in the attribute
> "customerCrypto" in base64 format.
> Decryption of signed personal data of the user is taking place
> as required by the cryptographic message formats defined
> by order of the Administration of the State Service for Special Communication and Protection
> Information of Ukraine from 18.12.2012 № 739 (http://zakon3.rada.gov.ua/laws/show/z0108-13) (hereinafter - Requirements).
> Default key matching is done with
> using a static mechanism. If the parameters are cryptographic
> The static key pair algorithm of the sender is not equivalent to the parameters
> cryptographic algorithm of static payee key pair, must
> move to the use of a dynamic coordination mechanism
> keys. Cryptographic security tools for sender and
> The recipient must support the cryptographic algorithms defined by these
> Requirements.

Sample response format:

```
HTTP/1.1 200 OK
Content-Type: application/json
{
  "state": "ok",
  "cert":"dEBIGx1pdL6dt1ngaOEfPvt/ik9eUpDuz90rm/Vk23v+FtiKJEvGnuea9FGjvBMGlFZS4zhg2IYIHGOhlBVYrZcez6udotjZlCLGZ7zwPuFo0XypKDQj5qpR7w0rFFZNjcPH3JW2IzEUv",
  "customerCrypto": “dEBIGx1pdL6dt1ngaOEfPvt/ik9eUpDuz90rm/Vk23v+FtiKJEvGnuea9FGjvBMGlF
  ZS4zhg2IYIHGOhlBVYrZcez6udotjZlCLGZ7zwPuFo0XypKDQj5qpR7w0rFFZNjc
  PH3JW2IzEUv/4bXQWqYCccma03b3lbva+YJ/Txox1CMfyV4jJ5fXeCMOjEWxwc
  tEc7mXNzPfcbKMoqr048uvW9HTiPkjsLIU5jgTKJVdgoanZI4712dmQev5UzMKq
  NYvOwfJ+hU872kCSD1wfgVaJU0qP6yURcK80ys2K5OvUpa9uIHwmL7KmnxM
  hB4hLr5CQPl1XZ09RnNykgS/4cQ”
}
```

**Clarification**:

- returned **cert** is public certificate from BankId system
- **customerCrypto** is base64 encoded cryptographic message, format defined by http://www.dsszzi.gov.ua/dsszzi/control/uk/publish/article?showHidden=1&art_id=94570&cat_id=38837&cti

**customerCrypto** has following ASN.1/DER structure:

```
SEQUENCE {
   OBJECTIDENTIFIER 1.2.840.113549.1.7.3 (envelopedData)
   [0] {
      SEQUENCE {
         INTEGER 0x02 (2 decimal)
         SET {
            SEQUENCE {
               INTEGER 0x02 (2 decimal)
               [0] c35e86996709293916a881dd98567867bdd9244c
               SEQUENCE {
                  OBJECTIDENTIFIER 1.2.840.113549.1.1.1 (rsaEncryption)
                  NULL
               }
               OCTETSTRING 876f8d9.... -- 256 bytes ecnrypted session key (SK), you can decode it with your private RSA key
            }
         }
         SEQUENCE {
            OBJECTIDENTIFIER 1.2.840.113549.1.7.1 (data)
            SEQUENCE {
               OBJECTIDENTIFIER 1.2.804.2.1.1.1.1.1.1.2 -- Encryption algorithm Gost28147ctr Алгоритм ДСТУ ГОСТ 28147:2009 в режимі гамування
               SEQUENCE {
                  OCTETSTRING 9bc3c19717a6d017 -- IV (initialization vector) for Gost28147ctr
               }
            }
            [0] 46c8d2d59d992380.... -- response data encrypted with Gost28147ctr using provided SK/IV
```

After decryption you get another digital envelope:

```
SEQUENCE {
   OBJECTIDENTIFIER 1.2.840.113549.1.7.2 (signedData)
   [0] {
      SEQUENCE {
         INTEGER 0x01 (1 decimal)
         SET {
            SEQUENCE {
               OBJECTIDENTIFIER 1.2.804.2.1.1.1.1.2.1
            }
         }
         SEQUENCE {
            OBJECTIDENTIFIER 1.2.840.113549.1.7.1 (data)
            [0] {
               -- actual JSON object, like {"inn":"3010210139","birthDay":"21.02.1982","clId":"6299E05EC5D568...
               OCTETSTRING 7b22696e6e223a2233303130323130313339222c226269727468446179223a2232312e30322e31393832222c22636c4964223a223632393945303545433544353638
            }
         }
         [0] {
            SEQUENCE { -- rest of data is not interesting, contains info about used signing certifcates
               SEQUENCE {
                  [0] {
                     INTEGER 0x02 (2 decimal)
                  }
                  INTEGER 0x02c4fb (181499 decimal)
                  SEQUENCE {
                     OBJECTIDENTIFIER 1.2.804.2.1.1.1.1.3.1.1
                  }
                  SEQUENCE {
                     SET {
                        SEQUENCE {
                           OBJECTIDENTIFIER 2.5.4.5 (serialNumber)
                           PrintableString 'UA-00032129-2016'
                        }
                     }
```


