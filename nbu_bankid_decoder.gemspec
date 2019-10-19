Gem::Specification.new do |s|
  s.name        = 'nbu_bankid_decoder'
  s.version     = '0.0.1'
  s.date        = '2019-10-19'
  s.summary     = "Decoder for NBU BankID"
  s.description = "Decodes NBU BankID encrypted envelopes (customerCrypto)"
  s.authors     = ["Nikolajs Lugovojs"]
  s.email       = 'nik@ithouse.lv'
  s.extensions = %w[ext/nbu_bankid_decoder/extconf.rb]
  s.files       = [
    "lib/nbu_bankid_decoder.rb",
    "lib/nbu_bankid_decoder/asn_tools.rb",
    "ext/nbu_bankid_decoder/extconf.rb",
    "ext/nbu_bankid_decoder/byte_array.c",
    "ext/nbu_bankid_decoder/byte_array.h",
    "ext/nbu_bankid_decoder/byte_array_internal.c",
    "ext/nbu_bankid_decoder/byte_array_internal.h",
    "ext/nbu_bankid_decoder/byte_utils_internal.c",
    "ext/nbu_bankid_decoder/byte_utils_internal.h",
    "ext/nbu_bankid_decoder/cryptonite_errors.h",
    "ext/nbu_bankid_decoder/dstu4145_prng_internal.c",
    "ext/nbu_bankid_decoder/dstu4145_prng_internal.h",
    "ext/nbu_bankid_decoder/extconf.rb",
    "ext/nbu_bankid_decoder/gost28147.c",
    "ext/nbu_bankid_decoder/gost28147.h",
    "ext/nbu_bankid_decoder/gost34_311.c",
    "ext/nbu_bankid_decoder/gost34_311.h",
    "ext/nbu_bankid_decoder/macros_internal.h",
    "ext/nbu_bankid_decoder/nbu_bankid_decoder.c",
    "ext/nbu_bankid_decoder/prng.c",
    "ext/nbu_bankid_decoder/prng.h",
    "ext/nbu_bankid_decoder/pthread_internal.h",
    "ext/nbu_bankid_decoder/stacktrace.c",
    "ext/nbu_bankid_decoder/stacktrace.h"
  ]
  s.homepage    = 'https://github.com/nikolailv/nbu_bankid_decoder'
  s.require_paths = ["lib", "ext"]
  s.license     = 'BSD-3-Clause'
end
