#include <iostream>

using namespace std;

void test(const int& x) {
    cout << "1" << endl;
}

void test2(int&& x) {
    cout << "3" << endl;
}

void test(int&& x) {
    cout << "2" << endl;
    // test2(x); // this doesn't work :(
    // test2(std::move(x));  // this works!
}

int main() {
    test(5);
    return 0;
}
