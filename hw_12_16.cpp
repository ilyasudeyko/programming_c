#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

void processFiles(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    
    if (!outFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    string line, number;
    
    // Читаємо числа з файлу F (вхідний файл)
    while (getline(inFile, line, '\t')) {
        istringstream iss(line);
        
        while (iss >> number) {
            try {
                // Перетворюємо рядок на ціле число
                int num = stoi(number);
                
                // Перевіряємо, чи є число додатним
                if (num > 0) {
                    // Записуємо число і його корінь у файл G (вихідний файл)
                    outFile << num << "," << fixed << setprecision(5) << sqrt(num) << endl;
                }
            } catch (invalid_argument&) {
                cerr << "Invalid number: " << number << endl;
            }
        }
    }

    // Закриваємо файли
    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "F.txt";
    string outputFile = "G.txt";

    processFiles(inputFile, outputFile);

    cout << "Processing completed!" << endl;
    
    return 0;
}
