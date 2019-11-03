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
rec1value ContentInfo ::=
{
  contentType { 1 2 840 113549 1 7 3 }  -- id-envelopedData --,
  content
  {
    version v2,
    recipientInfos
    {
      kari :
        {
          version v3,
          originator originatorKey :
            {
              algorithm
              {
                algorithm { 1 2 804 2 1 1 1 1 3 1 1 }  -- id-dstu4145PB --,
                parameters '0500'H
              },
              publicKey '00000100 00110110 10010001 01010110 010 ...'B
            },
          keyEncryptionAlgorithm
          {
            algorithm { 1 2 804 2 1 1 1 1 3 4 }  -- id-dhSinglePass-cofactorDH-gost34311kdf-scheme --,
            parameters '300F060B2A862402010101010101050500'H
          },
          recipientEncryptedKeys
          {
            {
              rid rKeyId :
                {
                  subjectKeyIdentifier 'F5E15FFCA5F626A05CCE7BF70AAD336527 ...'H
                },
              encryptedKey 'D753D0F360DD9BECF9C8586AC26E02B33B ...'H
            }
          }
        }
    },
    encryptedContentInfo
    {
      contentType { 1 2 840 113549 1 7 1 }  -- id-data --,
      contentEncryptionAlgorithm
      {
        algorithm { 1 2 804 2 1 1 1 1 1 1 2 }  -- id-gost28147-ofb --,
        parameters '300A040827D3AAEA632228D8'H
      },
      encryptedContent 'C78AB166B15BAFDE50578ACDF3786DD621 ...'H
    }
  }
}
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

## Requirements for private key and certificate

To work with BankID protocols, certificate/key must meet following criteria:
- use defined DSTU protocols with Diffie-Hellman key agreement
- certificate must be signed by known authority
- certificate must be valid and can be checked with OCSP protocol

UA Docs

> 8.1. Сертифікат шифрування у цих Вимогах призначається для використання у протоколах узгодження ключа Діффі-Геллмана: DH в циклічній групі простого поля та в групі точок еліптичної кривої.
> 8.2. Формат сертифіката шифрування повинен відповідати Вимогам до формату посиленого сертифіката відкритого ключа.
> 8.3. Розширення сертифіката шифрування "Використання ключа".
> У розширенні "Використання ключа" ("keyUsage") повинно бути встановлено значення "узгодження ключа" ("keyAgreement"). Додатково можуть бути встановлені значення:
> "тільки зашифрування" ("encipherOnly");
> "тільки розшифрування" ("decipherOnly").
> У розширенні "Використання ключа" ("keyUsage") не повинні бути встановлені значення:
> "електронний цифровий підпис" ("digitalSignature");
> "електронний цифровий підпис у сертифікаті" ("keyCertSign");
> "електронний цифровий підпис у списку відкликаних сертифікатів" ("crlSign");
> "неспростовність" ("nonRepudiation");
> "шифрування ключа" ("keyEncipherment");
> "підписування сертифікатів" ("keyCertSign");
> "підписування списків відкликаних сертифікатів" ("cRLSign").

Google translate:

> 8.1. The encryption certificate in these Requirements is intended for use in Diffie-Gellman: DH key matching protocols in the simple-loop cyclic group and the elliptic curve point group.
> 8.2. The encryption certificate format must conform to the Enhanced Public Key Certificate format.
> 8.3. Key Usage Encryption Certificate Extension.
> The keyUsage extension must be set to "keyAgreement". Additionally, the following values can be set:
> "encryption only" ("encipherOnly");
> "decipherOnly" only.
> The keyUsage extension does not need to be set to: "digitalSignature", "keyCertSign", "crlSign", "nonRepudiation", "keyEncipherment","keyCertSign", "cRLSign".
