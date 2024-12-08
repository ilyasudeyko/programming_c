#include <stdio.h>

int isPowerOfTwoWithLoop(unsigned int n) {
    if (n == 0) return 0; // 0 не є ступенем двійки
    while (n > 1) {
        if (n % 2 != 0) return 0; // Якщо залишок від ділення на 2 не 0, то не ступінь двійки
        n /= 2;
    }
    return 1; // Якщо дійшли до 1, то число є ступенем двійки
}

int main() {
    unsigned int n;
    printf("Введіть натуральне число: ");
    scanf("%u", &n);

    if (isPowerOfTwoWithLoop(n))
        printf("%u є ступенем двійки (метод з циклом).\n", n);
    else
        printf("%u не є ступенем двійки (метод з циклом).\n", n);

    return 0;
}
