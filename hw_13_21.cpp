#include <iostream>
#include <string>

using namespace std;

void replaceWords(string& text) {
    // Масив для пар слів і відповідних чисел
    string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Заміна всіх слів на відповідні цифри
    for (int i = 0; i < 9; i++) {
        size_t pos = 0;
        while ((pos = text.find(words[i], pos)) != string::npos) {
            text.replace(pos, words[i].length(), 1, digits[i]);
            pos += 1;  // Пересуваємось вперед на довжину одного символа
        }
    }
}

int main() {
    string input;

    // Введення рядка користувачем
    cout << "Введіть рядок: ";
    getline(cin, input);

    // Виклик функції для заміни слів
    replaceWords(input);

    // Виведення результату
    cout << "Рядок після заміни: " << input << endl;

    return 0;
}
