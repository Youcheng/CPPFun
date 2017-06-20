#pragma once
#include<iostream>
#include "snip1.h"


namespace B {
    using A::f; // take a snapshot of whatever entities named f in namespace A have seen by the time the using declaration is encountered.
    void g();
}