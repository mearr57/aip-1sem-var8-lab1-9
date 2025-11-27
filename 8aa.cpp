#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Sportsman {
    string teamName;
    string lastName;
    int age;
    int height;
    double weight;
};


int inputInt(const string& prompt) {
    string input;
    bool validInput = false;
    int result = 0;
    
    while (!validInput) {
        cout << prompt;
        getline(cin, input);
        
        
        if (input.empty()) {
            cout << "Ошибка: введена пустая строка. Пожалуйста, введите число." << endl;
            continue;
        }
        
        try {
            result = stoi(input);
            validInput = true;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: '" << input << "' не является числом. Пожалуйста, введите заново." << endl;
        } 
        catch (const out_of_range& e) {
            cout << "Ошибка: число '" << input << "' выходит за пределы диапазона. Пожалуйста, введите заново." << endl;
        }
    }
    
    return result;
}


double inputDouble(const string& prompt) {
    string input;
    bool validInput = false;
    double result = 0.0;
    
    while (!validInput) {
        cout << prompt;
        getline(cin, input);
        
        
        if (input.empty()) {
            cout << "Ошибка: введена пустая строка. Пожалуйста, введите число." << endl;
            continue;
        }
        
        try {
            result = stod(input);
            validInput = true;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: '" << input << "' не является числом. Пожалуйста, введите заново." << endl;
        }
        catch (const out_of_range& e) {
            cout << "Ошибка: число '" << input << "' выходит за пределы диапазона. Пожалуйста, введите заново." << endl;
        }
    }
    
    return result;
}

list<Sportsman*> inputSportsmen() {
    list<Sportsman*> sportsmen;
    
    int count = inputInt("Введите количество спортсменов: ");
    
    for (int i = 0; i < count; i++) {
        Sportsman* sportsman = new Sportsman;
        
        cout << "\n=== Спортсмен " << i + 1 << " ===" << endl;
        
        cout << "Название команды: ";
        getline(cin, sportsman->teamName);
        
        cout << "Фамилия спортсмена: ";
        getline(cin, sportsman->lastName);
        
        sportsman->age = inputInt("Возраст: ");
        sportsman->height = inputInt("Рост (в см): ");
        sportsman->weight = inputDouble("Вес (в кг): ");
        
        sportsmen.push_back(sportsman);
    }
    
    return sportsmen;
}

void printTallSportsmen(const list<Sportsman*>& sportsmen) {
    cout << "\n=== Спортсмены с ростом выше 190 см ===" << endl;
    
    bool found = false;
    for (const auto& sportsman : sportsmen) {
        if (sportsman->height > 190) {
            cout << "Команда: " << sportsman->teamName << endl;
            cout << "Фамилия: " << sportsman->lastName << endl;
            cout << "Возраст: " << sportsman->age << " лет" << endl;
            cout << "Рост: " << sportsman->height << " см" << endl;
            cout << "Вес: " << sportsman->weight << " кг" << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Спортсменов с ростом выше 190 см не найдено." << endl;
    }
}

void freeMemory(list<Sportsman*>& sportsmen) {
    for (auto& sportsman : sportsmen) {
        delete sportsman;
    }
    sportsmen.clear();
}

int main() {
    list<Sportsman*> sportsmen = inputSportsmen();
    
    cout << "\n=== Все спортсмены ===" << endl;
    for (const auto& sportsman : sportsmen) {
        cout << sportsman->lastName << " (" << sportsman->teamName << ") - " 
             << sportsman->height << " см" << endl;
    }
    
    printTallSportsmen(sportsmen);
    freeMemory(sportsmen);
    
    return 0;
}