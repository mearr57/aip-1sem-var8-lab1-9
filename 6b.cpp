#include <iostream>
#include <iomanip>
#include <cmath>


double y(double x) {
    return std::exp(x) + std::exp(-x);
}


double s(double x, double epsilon) {
    double term_pos = 1.0; 
    double term_neg = 1.0; 
    double sum_pos = term_pos;
    double sum_neg = term_neg;
    int n = 1;

    while (std::abs(term_pos) > epsilon || std::abs(term_neg) > epsilon) {
        term_pos *= x / n;
        term_neg *= -x / n;
        sum_pos += term_pos;
        sum_neg += term_neg;
        ++n;
    }

    return sum_pos + sum_neg;
}

int main() {
    double a = -0.3;
    double b = 0.4;
    double epsilon = 1e-5;
    int steps = 10;
    double h = (b - a) / steps;

    std::cout << std::fixed << std::setprecision(8);
    std::cout << "------------------------------------------------------\n";
    std::cout << "|    x     |    y(x)     |    s(x) (Taylor)         |\n";
    std::cout << "------------------------------------------------------\n";

    for (int i = 0; i <= steps; ++i) {
        double x = a + i * h;
        double y_val = y(x);
        double s_val = s(x, epsilon);
        std::cout << " | " << std::setw(8) << x
                  << " | " << std::setw(11) << y_val
                  << " | " << std::setw(22) << s_val << "|\n";
    }

    std::cout << "------------------------------------------------------\n";
    return 0;
}
