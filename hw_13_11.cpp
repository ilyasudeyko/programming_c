#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string removeCharFromWord(const string& word, char symbol) {
    string result;
    for (char ch : word) {
        if (ch != symbol) {
            result += ch;
        }
    }
    return result;
}

string processString(const string& input, char symbol) {
    stringstream ss(input);
    string word, result;
    bool firstWord = true;

    // Використовуємо stringstream для обробки слів з урахуванням пробілів
    while (ss >> word) {
        if (!firstWord) {
            result += " ";  // Додаємо пробіл між словами
        }
        result += removeCharFromWord(word, symbol);
        firstWord = false;
    }

    // Зберігаємо кількість початкових і кінцевих пробілів
    size_t leadingSpaces = input.find_first_not_of(' ');
    size_t trailingSpaces = input.length() - input.find_last_not_of(' ') - 1;

    result = string(leadingSpaces, ' ') + result + string(trailingSpaces, ' ');

    return result;
}

int main() {
    string input;
    char symbol;

    // Введення рядка користувачем
    cout << "Введіть рядок: ";
    getline(cin, input);

    // Введення символу, який потрібно видалити
    cout << "Введіть символ для видалення: ";
    cin >> symbol;

    // Обробка рядка
    string result = processString(input, symbol);

    // Виведення результату
    cout << "Результат: " << result << endl;

    return 0;
}
