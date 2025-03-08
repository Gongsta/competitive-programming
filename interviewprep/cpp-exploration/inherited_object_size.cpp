#include <iostream>

using namespace std;
class A {
    int a;
};
class B : public A {
};

class C {};

int main() {
    cout << sizeof(B) << endl;  // 4
    cout << sizeof(C) << endl;  // 1. Why 1, and not 0? Because each object in C++ has a unique address. Having 0 size would violate this
}
