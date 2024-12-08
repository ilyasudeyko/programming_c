#include <stdio.h>

// Функція для обчислення факторіалу
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Введіть значення n: ");
    scanf("%d", &n);

    double Sn = 0; // Сума
    double a_k = 1; // Початкове значення a0 = 1

    for (int k = 1; k <= n; k++) {
        // Обчислення ak
        a_k = k * a_k + 1.0 / k;

        // Обчислення Sn
        Sn += (2.0 * k / factorial(k)) * a_k;
    }

    printf("Сума Sn = %.10f\n", Sn);

    return 0;
}
