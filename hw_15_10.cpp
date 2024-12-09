#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Клас "Валюта"
class Currency {
private:
    string name;    // Назва валюти
    int value;      // Основне значення (гривні, долари тощо)
    int cents;      // Субодиниці (копійки, центи)

public:
    // Конструктор за замовчуванням
    Currency(string n = "", int v = 0, int c = 0) : name(n), value(v), cents(c) {}

    // Метод для введення даних
    void input() {
        cout << "Введіть назву валюти: ";
        cin >> name;
        cout << "Введіть значення (ціле число): ";
        cin >> value;
        cout << "Введіть центи (копійки): ";
        cin >> cents;
    }

    // Метод для виведення даних
    void output() const {
        cout << "Назва валюти: " << name << ", Значення: " << value << "." << setw(2) << setfill('0') << cents << endl;
    }

    // Додавання валют
    Currency add(const Currency& other) const {
        if (name != other.name) {
            cout << "Помилка: різні валюти!" << endl;
            return *this;
        }
        
        int totalCents = (value * 100 + cents) + (other.value * 100 + other.cents);
        return Currency(name, totalCents / 100, totalCents % 100);
    }

    // Різниця валют
    Currency subtract(const Currency& other) const {
        if (name != other.name) {
            cout << "Помилка: різні валюти!" << endl;
            return *this;
        }

        int totalCents = (value * 100 + cents) - (other.value * 100 + other.cents);
        return Currency(name, totalCents / 100, totalCents % 100);
    }

    // Дружня функція для обміну валюти за курсом
    friend Currency exchange(const Currency& curr, double rate);
};

// Функція обміну валюти за курсом
Currency exchange(const Currency& curr, double rate) {
    int totalCents = static_cast<int>((curr.value * 100 + curr.cents) * rate);
    return Currency(curr.name, totalCents / 100, totalCents % 100);
}

// Клас "Товар"
class Product {
private:
    string name;         // Назва товару
    double price;        // Вартість товару
    string currency;     // Валюта в якій вимірюється вартість
    string unit;         // Одиниця вимірювання товару

public:
    // Конструктор за замовчуванням
    Product(string n = "", double p = 0.0, string c = "", string u = "") : name(n), price(p), currency(c), unit(u) {}

    // Метод для введення даних
    void input() {
        cout << "Введіть назву товару: ";
        cin >> name;
        cout << "Введіть вартість товару: ";
        cin >> price;
        cout << "Введіть валюту: ";
        cin >> currency;
        cout << "Введіть одиницю вимірювання: ";
        cin >> unit;
    }

    // Метод для виведення даних
    void output() const {
        cout << "Товар: " << name << ", Вартість: " << price << " " << currency << ", Одиниця: " << unit << endl;
    }

    // Додавання вартості товарів
    Product add(const Product& other) const {
        if (currency != other.currency || unit != other.unit) {
            cout << "Помилка: різні валюти або одиниці вимірювання!" << endl;
            return *this;
        }

        return Product(name, price + other.price, currency, unit);
    }

    // Різниця вартості товарів
    Product subtract(const Product& other) const {
        if (currency != other.currency || unit != other.unit) {
            cout << "Помилка: різні валюти або одиниці вимірювання!" << endl;
            return *this;
        }

        return Product(name, price - other.price, currency, unit);
    }

    // Дружня функція для обміну валюти за курсом
    friend Product exchange(const Product& prod, double rate);
};

// Функція обміну валюти за курсом
Product exchange(const Product& prod, double rate) {
    return Product(prod.name, prod.price * rate, prod.currency, prod.unit);
}

// Головна функція
int main() {
    Currency curr1("USD", 10, 50);
    Currency curr2("USD", 5, 25);
    
    curr1.output();
    curr2.output();
    
    Currency sum = curr1.add(curr2);
    Currency diff = curr1.subtract(curr2);
    
    sum.output();
    diff.output();
    
    Currency exchanged = exchange(curr1, 27.0);  // Приклад обміну за курсом
    exchanged.output();

    Product prod1("Laptop", 1000.0, "USD", "шт");
    Product prod2("Laptop", 500.0, "USD", "шт");

    prod1.output();
    prod2.output();

    Product prodSum = prod1.add(prod2);
    Product prodDiff = prod1.subtract(prod2);

    prodSum.output();
    prodDiff.output();

    Product exchangedProd = exchange(prod1, 27.0);  // Приклад обміну валюти
    exchangedProd.output();

    return 0;
}
