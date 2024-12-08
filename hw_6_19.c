#include <stdio.h>

int countOccurrencesOf11(unsigned int n) {
    int count = 0;

    // Перевірка кожної пари бітів
    while (n > 0) {
        if ((n & 3) == 3) { // 3 у двійковому вигляді - це 11
            count++;
        }
        n >>= 1; // Зсув на один біт праворуч
    }

    return count;
}

int main() {
    unsigned int number;
    printf("Введіть додатне ціле число: ");
    scanf("%u", &number);

    int result = countOccurrencesOf11(number);

    printf("Кількість разів, коли '11' зустрічається в двійковому поданні числа: %d\n", result);

    return 0;
}
