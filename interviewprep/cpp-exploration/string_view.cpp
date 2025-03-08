/*
What is the purpose of a string_view?
*/
#include <iostream>
#include <string_view>

void print(const std::string& s) {
    std::cout << s << std::endl;
}

// void print(std::string_view s) {
//     std::cout << s << std::endl;
// }

int main() {
    print("hello world");
    return 0;
}
