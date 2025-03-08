#include <cstdlib>
#include <iostream>

int main() {
    float acc = 0;
    float a[16];
    float b[16];
    float c[16];
    for (int i = 0; i < 16; i++) {
        a[i] = rand();
        b[i] = rand();
    }
    // Could not get this to vectorize on arm :(
    for (int i = 0; i < 16; i++) {
        c[i] = a[i] * b[i];
    }
    for (int i = 0; i < 16; i++) {
        std::cout << c[i] << std::endl;
    }
    return 0;
}
// #include <arm_neon.h>

// #include <cstdlib>
// #include <iostream>

// int main() {
//     float32_t a[16], b[16], c[16];

//     // Initialize arrays
//     for (int i = 0; i < 16; i++) {
//         a[i] = rand();
//         b[i] = rand();
//     }

//     // Perform SIMD multiplication in chunks of 4 floats (128 bits)
//     for (int i = 0; i < 16; i += 4) {
//         float32x4_t va = vld1q_f32(&a[i]);   // Load 4 floats
//         float32x4_t vb = vld1q_f32(&b[i]);   // Load 4 floats
//         float32x4_t vc = vmulq_f32(va, vb);  // Multiply
//         vst1q_f32(&c[i], vc);                // Store result
//     }

//     for (int i = 0; i < 16; i++) {
//         std::cout << c[i] << std::endl;
//     }

//     return 0;
// }
