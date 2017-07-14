http://en.cppreference.com/w/cpp/language/object

alignment
---------
    Every object type has the property called alignment requirement,
    which is an integer value (of type std::size_t, always a power of 2)
    representing the number of bytes between successive addresses
    at which objects of this type can be allocated.

    An object doesn’t just need enough storage to hold its representation. 
    In addition, on some machine architectures, the bytes used to hold it 
    must have proper alignment for the hardware to access it efficiently 
    (or in extreme cases to access it at all).

word size
---------
    32 bit machine, the processing word size is 4 bytes
    64 bit machine, the processing word size is 8 bytes

- http://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/

    [ylin@cr-pvg-dev002 CLionProjects]$ cat /proc/cpuinfo | grep cache_alignment
    cache_alignment	: 64                                                     <-- 64 bits
    cache_alignment	: 64

