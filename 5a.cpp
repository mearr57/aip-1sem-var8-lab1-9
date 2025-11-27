#include <iostream>
using namespace std;

int main() {
    const int ROWS = 5;
    const int COLS = 5;
    double array[ROWS][COLS];
    
    cout << "Введите элементы двумерного массива " << ROWS << "x" << COLS << ":\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < COLS; j++) {
            cin >> array[i][j];
        }
    }
    
    cout << "\nВведенный массив:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    
    
    double sum = 0;
    int count = 0;
    
    for (int i = 0; i < ROWS; i += 2) { 
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
            count++;
        }
    }
    
    
    if (count > 0) {
        double average = sum / count;
        cout << "Сумма: " << sum << ", количество элементов: " << count << endl;
        cout << "\nСреднее значение элементов нечетных строк: " << average << endl;
        
    } else {
        cout << "\nНет элементов для вычисления среднего значения." << endl;
    }
    
    return 0;
}