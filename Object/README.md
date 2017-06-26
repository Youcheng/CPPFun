http://en.cppreference.com/w/cpp/language/object

Every object type has the property called alignment requirement,
which is an integer value (of type std::size_t, always a power of 2)
representing the number of bytes between successive addresses
at which objects of this type can be allocated.

32 bit machine, the processing word size is 4 bytes
64 bit machine, the processing word size is 8 bytes


http://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/

[ylin@cr-pvg-dev002 CLionProjects]$ lscpu
Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                24
On-line CPU(s) list:   0-23
Thread(s) per core:    2                                                  <---hyperthreading is on
Core(s) per socket:    6
Socket(s):             2
NUMA node(s):          2
Vendor ID:             GenuineIntel
CPU family:            6
Model:                 63
Model name:            Intel(R) Xeon(R) CPU E5-2620 v3 @ 2.40GHz
Stepping:              2
CPU MHz:               1203.750
BogoMIPS:              4803.85
Virtualization:        VT-x
L1d cache:             32K                                               <-- L1 data cache, 32 kilo bytes
L1i cache:             32K                                               <-- L1 instruction cache, 32 kilo bytes
L2 cache:              256K
L3 cache:              15360K
NUMA node0 CPU(s):     0-5,12-17
NUMA node1 CPU(s):     6-11,18-23

[ylin@cr-pvg-dev002 CLionProjects]$ cat /proc/cpuinfo | grep cache_alignment
cache_alignment	: 64                                                     <-- 64 bits
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
cache_alignment	: 64
