struct ExampleStruct {
    using MyType = int;  // Public by default
};

class ExampleClass {
    using MyType = int;  // Private by default
};

int main() {
    ExampleStruct::MyType a = 5;  // ✅ Works (public)

    ExampleClass::MyType b = 5;  // ❌ Error(private)

    return 0;
}
