require "mkmf"
$CPPFLAGS << %[ -DCRYPTONITE_EXPORT='' ]
$CFLAGS << %[ -lm ]
create_makefile 'nbu_bankid_decoder/nbu_bankid_decoder'
