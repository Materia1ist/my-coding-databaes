#include <iostream>
#include <limits>

int main() {
    unsigned long long n = 1000000000000000000ULL - 2;
    unsigned long long m = 1000000000000000000ULL - 1;
    unsigned long long tx = 2;

    unsigned long long result = (n - tx + 1) * (n + m + tx - 4);

    std::cout << "Result: " << result << std::endl;

    return 0;
}