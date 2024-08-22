#include <iostream>
using namespace std;

// Function to calculate num raised to the power of pow using exponentiation by squaring
double power(double num, int pow) {
    // Handle the special case where the power is 0
    if (pow == 0) {
        return 1;  // Any number raised to the power of 0 is 1
    }

    // Handle negative exponents
    if (pow < 0) {
        num = 1.0 / num;
        pow = -pow;
    }

    double result = 1.0;

    while (pow > 0) {
        // If pow is odd, multiply result by num
        if (pow % 2 == 1) {
            result *= num;
        }
        // Square the base
        num *= num;
        // Divide pow by 2
        pow /= 2;
    }

    return result;
}

int main() {
    double num;  // Variable to hold the base number
    cout << "Enter the number: ";
    cin >> num;  // Read the base number from user input

    int pow;  // Variable to hold the exponent value
    cout << "Enter the power of the number: ";
    cin >> pow;  // Read the exponent value from user input

    // Call the power function and store the result
    double result = power(num, pow);

    // Output the result to the user
    cout << "Result: " << result << endl;
    return 0;  // Return 0 to indicate successful execution
}
