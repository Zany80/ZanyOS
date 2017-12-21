# Error codes

This file contains a list of all possible error codes and their meanings.

* 0x00000000: multiboot header not found. Frankly, this should never happen - if
it does, please report it in IRC or Discord.
* 0x00000001: returned from main. Again, this should never happen, report on IRC
or Discord.
* 0x00000002: no video information provided through multiboot. Note that there
is a special exception made for qemu for development purposes.
