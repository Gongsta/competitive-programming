/*
Can you do polymorphism with just refences?
*/
#include <iostream>

struct Shape {
    virtual int getArea() = 0;
};

struct Square : Shape {
    int side;
    Square(int side) : side{side} {}
    virtual int getArea() override {
        return side * side;
    }
};

struct Rectangle : Shape {
    int width;
    int height;
    Rectangle(int width, int height) : width{width}, height{height} {}
    virtual int getArea() override {
        return width * height;
    }
};

void printArea(Shape& shape) {  // The reference is absolutely mandatory here
    std::cout << shape.getArea() << std::endl;
};

int main() {
    Square square{5};
    Rectangle rectangle{5, 10};
    printArea(square);
    printArea(rectangle);
}
