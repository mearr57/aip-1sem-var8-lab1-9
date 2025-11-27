#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    FILE *binFile, *textFile;
    double numbers[10];
    double num;
    int i;

    
    binFile = fopen("numbers.bin", "wb");
    if (binFile == NULL) {
        cout << "Ошибка при создании бинарного файла!" << endl;
        return 1;
    }

    cout << "Введите 10 действительных чисел:" << endl;
    for (i = 0; i < 10; i++) {
        cin >> numbers[i];
        fwrite(&numbers[i], sizeof(double), 1, binFile);
    }
    fclose(binFile);

    
    binFile = fopen("numbers.bin", "rb");
    if (binFile == NULL) {
        cout << "Ошибка при открытии бинарного файла!" << endl;
        return 1;
    }

    
    textFile = fopen("result.txt", "w");
    if (textFile == NULL) {
        cout << "Ошибка при создании текстового файла!" << endl;
        return 1;
    }

    
    double sumPositive = 0, sumNegative = 0;
    for (i = 0; i < 10; i++) {
        fread(&num, sizeof(double), 1, binFile);
        if (num > 0) {
            sumPositive += fabs(num);
        } else if (num < 0) {
            sumNegative += fabs(num);
        }
    }

    
    double diff = sumPositive - sumNegative;

    
    cout << "Сумма модулей положительных чисел: " << sumPositive << endl;
    cout << "Сумма модулей отрицательных чисел: " << sumNegative << endl;
    cout << "Разность: " << diff << endl;

    
    fprintf(textFile, "Сумма модулей положительных чисел: %.2f\n", sumPositive);
    fprintf(textFile, "Сумма модулей отрицательных чисел: %.2f\n", sumNegative);
    fprintf(textFile, "Разность: %.2f\n", diff);

    
    fclose(binFile);
    fclose(textFile);

    cout << "Результат записан в файл result.txt" << endl;

    return 0;
}