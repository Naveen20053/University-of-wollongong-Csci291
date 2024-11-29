#include <iostream>
#include <iomanip> 

// Function to print a float in fixed point notation
void print_real(float number, int fieldspace, int precision) {
    std::cout << std::setw(fieldspace) << std::fixed << std::setprecision(precision) << number << std::endl;
}

// Template function to update m1 and m2
template <typename T>
void update_scale(T& m1, T& m2, T m3 = 10) {
    T original_m1 = m1;
    T original_m2 = m2;
    
    // Update m1: (m1 + m2) * m3
    m1 = (original_m1 + original_m2) * m3;
    
    // Update m2: (m1 - m2) * m3
    m2 = (original_m1 - original_m2) * m3;
}

int main() {
    float number = 12.3456;
    int fieldspace = 10;
    int precision = 3;
    
    // Part a: Printing the number
    print_real(number, fieldspace, precision);
    
    // Part b: Using the update_scale template function
    int a = 5, b = 3;
    
    std::cout << "Before update_scale: a = " << a << ", b = " << b << std::endl;
    update_scale(a, b); // m3 defaults to 10
    std::cout << "After update_scale: a = " << a << ", b = " << b << std::endl;
    
    return 0;
}
