#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    bool validInput = false;
    
    
    while (!validInput) {
        cout << "Введите строку с числами: ";
        getline(cin, input);
        
        cout << "Исходная строка: " << input << endl;
        
        string result = "";
        string curNumber = "";
        bool hasErrors = false;
        
        input += " ";
        
        for (char c : input) {
            if (c != ' ') {
                curNumber += c;  
            } else if (!curNumber.empty()) {
                
                try {
                    int number = stoi(curNumber);
                    if (number % 2 != 0) {
                        if (!result.empty()) {
                            result += " ";
                        }
                        result += curNumber;
                    }
                }
                catch (const invalid_argument& e) {
                    cout << "Ошибка: '" << curNumber << "' не является числом" << endl;
                    hasErrors = true;
                }
                catch (const out_of_range& e) {
                    cout << "Ошибка: число '" << curNumber << "' выходит за пределы диапазона" << endl;
                    hasErrors = true;
                }
                
                curNumber = "";  
            }
        }
        
        if (hasErrors) {
            cout << "Обнаружены ошибки ввода. Пожалуйста, введите строку заново.\n" << endl;
        } else {
            validInput = true;
            cout << "Результат удаления четных чисел: " << result << endl;
        }
    }
    
    return 0;
}