#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int size;
    
    cout << "Введите размер массива: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Ошибка: размер массива должен быть положительным числом!" << endl;
        return 1;
    }
    
    double* arr = new double[size];
    
    cout << "Введите " << size << " действительных чисел:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
    
   
    cout << "\nИсходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    int* toDelete = new int[size](); 
    int deleteCount = 0;
    
    for (int i = 0; i < size - 1; i++) {
        
        if (arr[i] > 0 && arr[i + 1] < 0) {
            toDelete[i] = 1; 
            deleteCount++;
        }
    }
    
    
    int newSize = size - deleteCount;
    double* newArr = new double[newSize];
    
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (!toDelete[i]) { 
            newArr[newIndex] = arr[i];
            newIndex++;
        }
    }
    
    
    cout << "\nРезультаты:" << endl;
    cout << "Найдено элементов для удаления: " << deleteCount << endl;
    
    if (deleteCount > 0) {
        cout << "Удаленные элементы: ";
        for (int i = 0; i < size; i++) {
            if (toDelete[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    
    cout << "Массив после удаления: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;
    
    
    delete[] arr;
    delete[] toDelete;
    delete[] newArr;
    
    return 0;
}
 