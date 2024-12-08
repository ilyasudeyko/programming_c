#include <stdio.h>

// Функція для обчислення числа pi з заданою точністю ε
double compute_pi(double epsilon) {
    double pi_div_2 = 1.0; // Початкове значення для добутку, яке буде дорівнювати π/2
    double prev_pi = 0.0;  // Попереднє значення для перевірки точності
    double factor;         // Поточний множник
    int k = 1;             // Лічильник ітерацій

    // Обчислюємо послідовність до досягнення точності
    while (2 * (pi_div_2 - prev_pi) > epsilon) {
        prev_pi = pi_div_2; // Зберігаємо попереднє значення

        // Обчислюємо множник для поточного k
        if (k % 2 == 1) {
            factor = (double)(k + 1) / k;  // Непарні індекси: k+1/k
        } else {
            factor = (double)(k + 1) / (k + 2);  // Парні індекси: k+1/(k+2)
        }

        pi_div_2 *= factor;  // Множимо на поточний фактор
        k++;                 // Збільшуємо лічильник
    }

    // Повертаємо значення pi
    return pi_div_2 * 2;
}

int main() {
    double epsilon;

    // Введення точності ε
    printf("Введіть точність ε: ");
    scanf("%lf", &epsilon);

    // Обчислення числа pi
    double pi = compute_pi(epsilon);

    // Виведення результату
    printf("Обчислене значення числа π: %.15lf\n", pi);

    return 0;
}
