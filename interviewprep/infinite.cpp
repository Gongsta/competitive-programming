class Test {
   public:
    Test() {};
    Test(const Test& d) {};
};

int main() {
    const Test t;
    Test d{t};
}
