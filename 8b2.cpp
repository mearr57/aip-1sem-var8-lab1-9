#include <iostream>
#include <string>
#include <list>
#include <locale>

using namespace std;

struct Sportsman {
    string teamName;
    string lastName;
    int age;
    int height;
    double weight;
};


bool containsOnlyLetters(const string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!isalpha(c) && c != ' ' && c != '-') {
            return false;
        }
    }
    return true;
}


int inputInt(const string& prompt) {
    string input;
    bool validInput = false;
    int result = 0;
    
    while (!validInput) {
        cout << prompt;
        getline(cin, input);
        
        try {
            result = stoi(input);
            validInput = true;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: '" << input << "' не является числом. Пожалуйста, введите целое число." << endl;
        }
        catch (const out_of_range& e) {
            cout << "Ошибка: число '" << input << "' выходит за пределы диапазона. Пожалуйста, введите другое число." << endl;
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
        
        try {
            result = stod(input);
            validInput = true;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: '" << input << "' не является числом. Пожалуйста, введите число." << endl;
        }
        catch (const out_of_range& e) {
            cout << "Ошибка: число '" << input << "' выходит за пределы диапазона. Пожалуйста, введите другое число." << endl;
        }
    }
    
    return result;
}

bool compareLastNames(const Sportsman* a, const Sportsman* b) {
    return a->lastName < b->lastName;
}

list<Sportsman*> inputSportsmen() {
    list<Sportsman*> sportsmen;
    int count;
    
    cout << "Введите количество спортсменов: ";
    cin >> count;
    cin.ignore();
    
    for (int i = 0; i < count; i++) {
        Sportsman* sportsman = new Sportsman;
        
        cout << "\n=== Спортсмен " << i + 1 << " ===" << endl;
        
        
        cout << "Название команды: ";
        getline(cin, sportsman->teamName);
        
        
        bool validLastName = false;
        while (!validLastName) {
            cout << "Фамилия спортсмена: ";
            getline(cin, sportsman->lastName);
            
            if (containsOnlyLetters(sportsman->lastName)) {
                validLastName = true;
            } else {
                cout << "Ошибка: Фамилия должна содержать только буквы, пробелы и дефисы. Попробуйте снова." << endl;
            }
        }
        
        
        bool validAge = false;
        while (!validAge) {
            sportsman->age = inputInt("Возраст: ");
            if (sportsman->age > 0 && sportsman->age < 150) {
                validAge = true;
            } else {
                cout << "Ошибка: Возраст должен быть от 1 до 150 лет. Попробуйте снова." << endl;
            }
        }
        
        
        bool validHeight = false;
        while (!validHeight) {
            sportsman->height = inputInt("Рост (в см): ");
            if (sportsman->height > 50 && sportsman->height < 300) {
                validHeight = true;
            } else {
                cout << "Ошибка: Рост должен быть от 50 до 300 см. Попробуйте снова." << endl;
            }
        }
        
        
        bool validWeight = false;
        while (!validWeight) {
            sportsman->weight = inputDouble("Вес (в кг): ");
            if (sportsman->weight > 20 && sportsman->weight < 300) {
                validWeight = true;
            } else {
                cout << "Ошибка: Вес должен быть от 20 до 300 кг. Попробуйте снова." << endl;
            }
        }
        
        sportsmen.push_back(sportsman);
    }
    
    return sportsmen;
}

void printYoungSportsmen(list<Sportsman*>& sportsmen) {
    cout << "\n=== Спортсмены младше 18 лет (в алфавитном порядке) ===" << endl;
    
    list<Sportsman*> youngSportsmen;
    
    for (const auto& sportsman : sportsmen) {
        if (sportsman->age < 18) {
            youngSportsmen.push_back(sportsman);
        }
    }
    
    if (youngSportsmen.empty()) {
        cout << "Спортсменов младше 18 лет не найдено." << endl;
        return;
    }
    
    youngSportsmen.sort(compareLastNames);
    
    for (const auto& sportsman : youngSportsmen) {
        cout << "Фамилия: " << sportsman->lastName << endl;
        cout << "Команда: " << sportsman->teamName << endl;
        cout << "Возраст: " << sportsman->age << " лет" << endl;
        cout << "Рост: " << sportsman->height << " см" << endl;
        cout << "Вес: " << sportsman->weight << " кг" << endl;
        cout << "------------------------" << endl;
    }
}

void printAllSportsmen(const list<Sportsman*>& sportsmen) {
    cout << "\n=== Все спортсмены ===" << endl;
    int counter = 1;
    for (const auto& sportsman : sportsmen) {
        cout << counter++ << ". " << sportsman->lastName << " (" 
             << sportsman->teamName << ") - " << sportsman->age << " лет" << endl;
    }
}

void freeMemory(list<Sportsman*>& sportsmen) {
    for (auto& sportsman : sportsmen) {
        delete sportsman;
    }
    sportsmen.clear();
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    cout << "=== Программа учета спортсменов ===" << endl;
    
    list<Sportsman*> sportsmen = inputSportsmen();
    printAllSportsmen(sportsmen);
    printYoungSportsmen(sportsmen);
    freeMemory(sportsmen);
    
    return 0;
}