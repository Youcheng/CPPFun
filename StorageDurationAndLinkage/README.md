http://en.cppreference.com/w/cpp/language/storage_duration

# Storage Duration of objects(at runtime)
- automatic<br>
 allocated at begin of the block and deallocated at end of block

- static<br>
 allocated at begin of the program and deallocated at end of program

- thread<br>
allocated at begin of a thread and deallocated at the end of the thread

- dynamic<br>
allocated/deallocated per request


# Linkage(at compile time)
- Linkage of a name, (object, reference, function, type, template, namespace, or value)<br>
If a name has linkage, it refers to the same entity as the same name introduced by a declaration in another scope.

- No linkage<br>
The name can be referred to only from the scope it is in.

- Internal linkage<br>
The name can be referred to from all scopes in the current translation unit.

- External linkage<br>
The name can be referred to from the scopes in the other translation units.