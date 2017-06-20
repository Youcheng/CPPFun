https://gcc.gnu.org/wiki/Visibility


In your header files, wherever you want an interface or API made public outside the current DSO, place __attribute__ ((visibility ("default")))
in struct, class and function declarations you wish to make public (it's easier if you define a macro as this).

You don't need to specify it in the definition. Then, alter your make system to pass -fvisibility=hidden to each call of GCC compiling a source file.