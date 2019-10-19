Gem::Specification.new do |s|
  s.name        = 'nbu_bankid_decoder'
  s.version     = '0.0.1'
  s.date        = '2019-10-19'
  s.summary     = "Decoder for NBU BankID"
  s.description = "Decodes NBU BankID encrypted envelopes (customerCrypto)"
  s.authors     = ["Nikolajs Lugovojs"]
  s.email       = 'nik@ithouse.lv'
  s.files       = [
    "lib/nbu_bankid_decoder.rb",
    "lib/nbu_bankid_decoder/asn_tools.rb",
    "ext/nbu_bankid_decoder/extconf.rb"
  ]
  s.homepage    = 'https://github.com/nikolailv/nbu_bankid_decoder'
  s.require_paths = ["lib", "ext"]
  s.license     = 'BSD'
end
