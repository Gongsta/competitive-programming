/*
Variadic max
*/
#include <iostream>

// template <typename T>
// T max(T t1, T t2) {
//     return t1 >= t2 ? t1 : t2;
// }

// template <typename T, typename... Args>
// T max(T t1, Args... args) {
//     T max_args = max(args...);
//     return (t1 >= max_args) ? t1 : max_args;
// }

int main() {
    std::cout << max(1, 2, 3, 4) << std::endl;
}
