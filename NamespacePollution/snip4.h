#pragma once
#include<iostream>
#include "snip2.h"

void B::g() {
    A::f(1); // if things work fine, int f(int) is supposed to be called give 1 is int.
}