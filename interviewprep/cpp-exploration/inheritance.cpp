#include <iostream>

class A {
   public:
    A() { std::cout << "A constructor\n"; }
};

class B : public A {
   public:
    B() { std::cout << "B constructor\n"; }
};

int main() {
    B b;
}
