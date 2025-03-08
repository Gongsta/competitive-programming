/*
static_cast is used when there is a known conversion at compile time. Else, it will throw.

This is better than just using the c-style casting, because it enforces type checking.
- But i thought there's also type checking for regular?

Is there more overhead to static_cast? No, because it's all done at compile time.

*/
#include <iostream>

struct Base {};
struct Derived : Base {};

struct Other {};
int main() {
    Base* a;
    (long long)a;              // allowed
    static_cast<Derived*>(a);  // allowed
    static_cast<Derived>(*a);  // allowed
    // static_cast<long long>(a);  // not allowed, Compiler error
    // static_cast<Other*>(a);     // Not allowed, because not related by inheritance
    const int val = 5;
    auto hi = static_cast<int*>(&val);  // not allowed, you need const_cast for that

    Derived* b;
    static_cast<Base>(*b);  // allowed
}
