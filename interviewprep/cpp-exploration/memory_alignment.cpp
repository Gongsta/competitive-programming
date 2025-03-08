#include <iostream>

struct A {
    char x1;    // [0, 1) byte offset
    double y1;  // [8, 16) byte offset
    char x2;    // [16, 17) byte offset
    double y2;  // [24, 32)
    char x3;    // [32, 33)
    double y3;  // [40, 48)
    char x4;    // [48, 49)
    double y4;  // [56, 64)
    char x5;    // [64, 65)
};  // sizeof(A) == 72 (because must be a multiple of largest type to be aligned)

struct B {
    char x1;    // [0,1)
    char x2;    // [1,2)
    char x3;    // [2,3)
    char x4;    // [3,4)
    char x5;    // [4,5)
    double y1;  // [8,16)
    double y2;  // [16,24)
    double y3;  // [24,32)
    double y4;  // [32,40)
};  // sizeof(B) == 40

int main() {
    static_assert(sizeof(A) == 72);
    static_assert(sizeof(B) == 40);
}
