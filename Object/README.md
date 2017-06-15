http://en.cppreference.com/w/cpp/language/object

Every object type has the property called alignment requirement,
which is an integer value (of type std::size_t, always a power of 2)
representing the number of bytes between successive addresses
at which objects of this type can be allocated.