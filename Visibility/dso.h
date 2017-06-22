#pragma once
/*
 *  With -fvisibility=hidden, you are telling GCC that every declaration not explicitly marked with a visibility attribute has a hidden visibility.
 *  And like in the example above, even for classes marked as visible (exported from the DSO),
 *  you may still want to mark e.g. private members as hidden, so that optimal code will be produced when calling them (from within the DSO).
 */
#include <iostream>

void __attribute__((visibility("default"))) publicFunction();

void __attribute__((visibility("hidden"))) privateFunction();
