/*
This is dangerous territory
*/

int main() {
    const int x = 5;
    // reinterpret_cast<int*>(&x); // still not allowed, you need const cast for that
    static_cast<long long>(x);
    reinterpret_cast<long long>(x);  // this is not allowed??
}
