/*
How does typeid work? Does it get the static type or the dynamic type?

https://en.cppreference.com/w/cpp/language/typeid

See my notes :)
*/
#include <iostream>
#include <typeinfo>

class Base {};
class Derived : public Base {};

class Base2 {  // polymorphic type
    virtual void foo() {};
};
class Derived2 : public Base2 {};

int main() {
    int x = 5;
    std::cout << "integer has type name: " << typeid(x).name() << std::endl;  // i
    int* int_p = &x;
    std::cout << "integer pointer has name: " << typeid(int_p).name() << std::endl;  // Pi
    Base* b = new Derived{};
    std::cout << typeid(*b).name() << std::endl;  // 4Base
    Base2* c = new Derived2{};
    std::cout << typeid(*c).name() << std::endl;  // 8Derived2
    std::cout << typeid(c).name() << std::endl;   // P5Base2

    const int y = 5;
    std::cout << typeid(y).name() << std::endl;
    // Derived2 d;
    // Base2& e = d;
    // std::cout << typeid(e).name() << std::endl;
}
