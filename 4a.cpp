#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    
    cout << "Введите " << SIZE << " целых чисел:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    
    cout << "\nВведенный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    
    
    double average = static_cast<double>(sum) / SIZE;
    
    
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < average) {
            count++;
        }
    }
    
    
    cout << "\nРезультаты:" << endl;
    cout << "Сумма всех элементов: " << sum << endl;
    cout << "Среднее значение: " << average << endl;
    cout << "Количество элементов меньше среднего: " << count << endl;
    
    
    cout << "Элементы меньше среднего (" << average << "): ";
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < average) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}