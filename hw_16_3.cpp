#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Базовий клас Person
class Person {
protected:
    string surname;  // Прізвище
public:
    Person(string s = "") : surname(s) {}

    // Отримати прізвище
    string getSurname() const {
        return surname;
    }

    // Виведення базової інформації
    virtual void printInfo() const {
        cout << "Прізвище: " << surname << endl;
    }
};

// Клас Passenger успадкований від Person
class Passenger : public Person {
private:
    string departure;    // Місце відправлення
    string destination;  // Місце призначення
    int seat;            // Місце пасажира

public:
    Passenger(string s = "", string dep = "", string dest = "", int seat = -1)
        : Person(s), departure(dep), destination(dest), seat(seat) {}

    // Отримати місце пасажира
    int getSeat() const {
        return seat;
    }

    // Отримати місце відправлення
    string getDeparture() const {
        return departure;
    }

    // Отримати місце призначення
    string getDestination() const {
        return destination;
    }

    // Виведення інформації про пасажира
    void printInfo() const override {
        Person::printInfo();
        cout << "Місце відправлення: " << departure << endl;
        cout << "Місце призначення: " << destination << endl;
        cout << "Місце пасажира: " << seat << endl;
    }

    // Запис пасажира у бінарний файл
    void writeToFile(ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(this), sizeof(Passenger));
    }

    // Читання пасажира з бінарного файлу
    static Passenger readFromFile(ifstream& inFile) {
        Passenger p;
        inFile.read(reinterpret_cast<char*>(&p), sizeof(Passenger));
        return p;
    }
};

// Клас Cashier, який працює з пасажирами
class Cashier {
private:
    vector<Passenger> passengers;  // Список пасажирів
    vector<bool> trainSeats;       // Місця у потягу (true = зайняте, false = вільне)

public:
    Cashier(int totalSeats) : trainSeats(totalSeats, false) {}

    // Додати пасажира
    void addPassenger(const Passenger& p) {
        if (p.getSeat() >= 0 && p.getSeat() < trainSeats.size() && !trainSeats[p.getSeat()]) {
            passengers.push_back(p);
            trainSeats[p.getSeat()] = true;
            cout << "Пасажир доданий." << endl;
        } else {
            cout << "Місце зайняте або некоректне!" << endl;
        }
    }

    // Записати список пасажирів у бінарний файл
    void savePassengersToFile(const string& filename) {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "Помилка відкриття файлу!" << endl;
            return;
        }

        for (const Passenger& p : passengers) {
            p.writeToFile(outFile);
        }

        outFile.close();
        cout << "Інформація про пасажирів збережена у файл." << endl;
    }

    // Завантажити список пасажирів з бінарного файлу
    void loadPassengersFromFile(const string& filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Помилка відкриття файлу!" << endl;
            return;
        }

        passengers.clear();
        while (inFile.peek() != EOF) {
            Passenger p = Passenger::readFromFile(inFile);
            passengers.push_back(p);
            trainSeats[p.getSeat()] = true;
        }

        inFile.close();
        cout << "Інформація про пасажирів завантажена з файлу." << endl;
    }

    // Пошук пасажира за прізвищем
    void findBySurname(const string& surname) const {
        for (const Passenger& p : passengers) {
            if (p.getSurname() == surname) {
                p.printInfo();
                return;
            }
        }
        cout << "Пасажира з прізвищем " << surname << " не знайдено." << endl;
    }

    // Пошук за місцем відправлення або прибуття
    void findByPlace(const string& place, bool isDeparture) const {
        for (const Passenger& p : passengers) {
            if ((isDeparture && p.getDeparture() == place) || (!isDeparture && p.getDestination() == place)) {
                p.printInfo();
            }
        }
    }

    // Знайти найближче вільне місце
    int findAvailableSeat() const {
        for (int i = 0; i < trainSeats.size(); ++i) {
            if (!trainSeats[i]) {
                return i;
            }
        }
        return -1;  // Якщо всі місця зайняті
    }

    // Вивести список усіх пасажирів
    void printAllPassengers() const {
        for (const Passenger& p : passengers) {
            p.printInfo();
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    // Створюємо касу на 10 місць
    Cashier cashier(10);

    // Створюємо кілька пасажирів
    Passenger p1("Ivanov", "Kyiv", "Lviv", 1);
    Passenger p2("Petrenko", "Kyiv", "Odessa", 3);
    Passenger p3("Sydorenko", "Lviv", "Kyiv", 5);

    // Додаємо пасажирів
    cashier.addPassenger(p1);
    cashier.addPassenger(p2);
    cashier.addPassenger(p3);

    // Записуємо пасажирів у файл
    cashier.savePassengersToFile("passengers.bin");

    // Очищуємо список пасажирів
    cashier.loadPassengersFromFile("passengers.bin");

    // Виводимо інформацію про пасажирів
    cashier.printAllPassengers();

    // Пошук пасажира за прізвищем
    cashier.findBySurname("Ivanov");

    // Пошук пасажирів за місцем відправлення
    cashier.findByPlace("Kyiv", true);  // Пошук за місцем відправлення

    // Пошук вільного місця
    int availableSeat = cashier.findAvailableSeat();
    if (availableSeat != -1) {
        cout << "Найближче вільне місце: " << availableSeat << endl;
    } else {
        cout << "Усі місця зайняті!" << endl;
    }

    return 0;
}
