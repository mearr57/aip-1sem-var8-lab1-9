#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateY(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        
        double firstPart = exp(2 * cos(i * x));
        double secondPart = exp(cos(i) * log(x));
        
        sum += firstPart * secondPart;
    }
    return sum;
}

int main() {
    double a, b;
    int n;
    
    cout << "Введите начальное значение a: ";
    cin >> a;
    cout << "Введите конечное значение b: ";
    cin >> b;
    cout << "Введите значение n: ";
    cin >> n;
    
    if (a >= b) {
        cout << "Ошибка: a должно быть меньше b!" << endl;
        return 1;
    }
    if (n <= 0) {
        cout << "Ошибка: n должно быть положительным числом!" << endl;
        return 1;
    }
    if (a <= 0) {
        cout << "Ошибка: a должно быть положительным числом (из-за x^cos(i))!" << endl;
        return 1;
    }
    

    double h = (b - a) / 10.0;
    
    
    cout << fixed << setprecision(6);
    cout << "\nТаблица значений функции y(x):\n";
    cout << "----------------------------------------\n";
    cout << setw(12) << "x" << setw(20) << "y(x)" << endl;
    cout << "----------------------------------------\n";
    
    
    for (int step = 0; step <= 10; step++) {
        double x = a + step * h;
        double y = calculateY(x, n);
        
        
        cout << setw(12) << x << setw(20) << y << endl;
    }
    
    cout << "----------------------------------------\n";
    
    return 0;
}
