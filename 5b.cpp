#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int rows, cols;
    
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    
    
    if (rows <= 0 || cols <= 0) {
        cout << "Ошибка: размеры массива должны быть положительными числами." << endl;
        return 1;
    }
    
    
    vector<vector<double>> matrix(rows, vector<double>(cols));
    
    
    cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nВведенная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    

    set<double> uniqueElements;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            uniqueElements.insert(matrix[i][j]);
        }
    }
    
  
    cout << "\nРезультат:" << endl;
    cout << "Количество различных элементов: " << uniqueElements.size() << endl;
    return 0;
}