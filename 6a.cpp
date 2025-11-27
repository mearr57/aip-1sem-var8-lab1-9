#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double y(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 3 * pow(x, 2*i) + 4 * exp(3*i);
    }
    return sum;
    }

int main() {
    
    double a = 0.23;
    double b = 0.9;
    int n = 5;
    
    double h = (b - a) / 10;
    
    cout << "Таблица значений функции y(x, n)" << endl;
    cout << "n = " << n << endl;
    cout << "x изменяется от " << a << " до " << b << " с шагом " << h << endl;
    cout << "----------------------------------------" << endl;
    cout << setw(10) << "x" << setw(20) << "y(x, n)" << endl;
    cout << "----------------------------------------" << endl;

    
    cout << fixed << setprecision(6);
    for (int i = 0; i <= 10; i++) {
        double x = a + i * h;
        double result = y(x, n);  
        cout << setw(10) << x << setw(20) << result << endl;
    }
    
    return 0;
}