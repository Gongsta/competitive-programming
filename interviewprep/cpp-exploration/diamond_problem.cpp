#include <iostream>

using namespace std;

struct A {
    int a;
};

struct B : A {};
struct C : A {};

struct D : B, C {};

int main() {
    D d;
    cout << d.B::a << endl;
}
