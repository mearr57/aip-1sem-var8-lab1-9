#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double a = 0.1;
    const double b = 1.0;
    const int k = 100;
    const int points = 10;
    const double h = (b - a) / points;
    

    cout << "Таблица значений функции y(x) = 5^x и ее разложения в ряд Тейлора" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << setw(4) << "x" << setw(15) << "s(x)" << setw(15) << "y(x)" << setw(15) << "Разность" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    cout << fixed << setprecision(6);
    
    for (int i = 0; i <= points; i++) {
        double x = a + i * h;
        double y = pow(5, x);  
        
        
        double s = 0.0;
        double term = 1.0;  
        
        for (int n = 0; n <= k; n++) {
            s += term;
            
            
            if (n < k) {
                term = term * x * log(5) / (n + 1);
            }
        }
        
        double difference = fabs(y - s);
        
        cout << setw(6) << x << setw(15) << s << setw(15) << y << setw(15) << endl;
    }
    
    return 0;
}