http://en.cppreference.com/w/cpp/language/storage_duration

Storage Duration of objects
*automatic
*allocated at begin of the block and deallocated at end of block

*static
*allocated at begin of the program and deallocated at end of program

*thread
*allocated at begin of a thread and deallocated at the end of the thread

*dynamic
*allocated/deallocated per request


Linkage of a name, (object, reference, function, type, template, namespace, or value)
If a name has linkage, it refers to the same entity as the same name introduced by a declaration in another scope.

*no linkage
The name can be referred to only from the scope it is in.

*internal linkage
The name can be referred to from all scopes in the current translation unit.


*external linkage
The name can be referred to from the scopes in the other translation units.