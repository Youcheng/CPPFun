#include "snip1.h"
#include "snip2.h"
#include "snip3.h"
#include "snip4.h"

int main() {
    // if things work fine, int f(int) is supposed to be called give 1 is int.
    // but it is polluted because we use using A::f; n snip2.h
    B::g();

}