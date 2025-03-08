#include <iostream>

template <typename T, int Value>
struct A {
    using t1 = T;
    static constexpr int t2 = Value;
};

template <typename T>
struct A<T, 5> {
    using t2 = T;
    static constexpr int t1 = 6;
};

int main() {
    A<int, 5> a;
    typename A<int, 5>::t2 v = A<int, 5>::t1;
    std::cout << v << std::endl;
}
