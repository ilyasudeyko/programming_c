#include <stdio.h>
#include <math.h>

int isPerfectSquare(int num) {
    if (num < 0) return 0; // Від'ємне число не може бути повним квадратом
    int root = (int)sqrt(num);
    return root * root == num;
}

int main() {
    int n, k, count = 0;

    // Введення кількості чисел
    printf("Введіть кількість чисел (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Кількість чисел повинна бути більшою за 0.\n");
        return 1;
    }

    int arr[n]; // Масив для збереження чисел

    // Введення чисел
    for (int i = 0; i < n; i++) {
        printf("Введіть число %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Обчислення k
    k = n / 2;

    // Перевірка чисел на повні квадрати
    for (int i = n - 1; i >= n - k - 1; i--) {
        if (isPerfectSquare(arr[i])) {
            count++;
        }
    }

    // Виведення результату
    printf("Кількість повних квадратів у заданому діапазоні: %d\n", count);

    return 0;
}
