#include <iostream>
#include <cstring>
#include <clocale>
#include <cwchar>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    const int MAX_SIZE = 1000;
    char input[MAX_SIZE];
    
    cout << "Введите строку (строка должна начинаться и заканчиваться пробелом): ";
    cin.getline(input, MAX_SIZE);
    
    
    int length = strlen(input);
    if (length == 0 || input[0] != ' ' || input[length - 1] != ' ') {
        cout << "Ошибка: строка должна начинаться и заканчиваться пробелом!" << endl;
        return 1;
    }
    
    cout << "Слова из двух символов: ";
    
    char currentWord[100]; 
    int wordIndex = 0;     
    bool found = false;    
    
    
    for (int i = 0; i <= length; i++) {
        
        if (input[i] != ' ' && input[i] != '\0') {
            currentWord[wordIndex++] = input[i];
        } 
        
        else if (wordIndex > 0) {
            currentWord[wordIndex] = '\0'; 
            
            if (wordIndex == 2) {
                cout << currentWord << " ";
                found = true;
            }
            
            wordIndex = 0; 
        }
    }
    
    if (!found) {
        cout << "слов не найдено";
    }
    
    cout << endl;
    
    return 0;
}