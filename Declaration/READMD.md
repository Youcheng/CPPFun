http://en.cppreference.com/w/cpp/language/declarations


decl-specifier-seq  --> type
init-declarator-seq  --> object/reference/function/typeAlias


How to interpret complex C/C++ declartions
https://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations
The right-left rule

#0 function pointer
int (*p)(char)
p
is a pointer
to a function taking char
and returns int

#1 function pointer
int * p char
p
is a pointer
to a function taking char
and returns a pointer
to int

#1
int (*(*foo)(double))[3]
foo
is a pointer
to a function taking double
and returns a pointer
to an arry of 3 ints

#2
int *( *( *arr[5])())()
arr
is an arrary of 5
pointers
to a function taking nothing
and returns a pointer
to a funtion taking nothing
and returns a pointer
to int