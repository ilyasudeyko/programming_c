#include <stdio.h>

// Функція для обчислення степеня x^k без використання бібліотеки <math.h>
double power(double x, int k) {
    double result = 1.0;
    for (int i = 0; i < k; i++) {
        result *= x;
    }
    return result;
}

// Функція для обчислення елемента x_k = x^k / k
double compute_element(double x, int k) {
    double x_power_k = power(x, k); // Обчислюємо x^k
    return x_power_k / k;           // Ділимо на k
}

int main() {
    double x;
    int k, n;

    // Введення значення x та кількості елементів послідовності n
    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть кількість елементів послідовності n: ");
    scanf("%d", &n);

    // Обчислення та виведення елементів послідовності
    for (k = 1; k <= n; k++) {
        double x_k = compute_element(x, k);
        printf("x_%d = %lf\n", k, x_k);
    }

    return 0;
}
