#include <stdio.h>

// Функція перевірки, чи всі елементи рядка негативні
int isRowNegative(int row[], int m) {
    for (int i = 0; i < m; i++) {
        if (row[i] >= 0) return 0; // Якщо хоча б один елемент не негативний
    }
    return 1;
}

// Функція для обміну рядків
void swapRows(int matrix[][100], int row1, int row2, int m) {
    for (int i = 0; i < m; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

int main() {
    int n, m;

    // Введення розмірів матриці
    printf("Введіть кількість рядків n: ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців m: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Розміри матриці повинні бути додатними.\n");
        return 1;
    }

    int matrix[100][100]; // Матриця

    // Введення елементів матриці
    printf("Введіть елементи матриці (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Перевірка першого і останнього рядка
    if (isRowNegative(matrix[0], m) && isRowNegative(matrix[n - 1], m)) {
        // Заміна рядків
        swapRows(matrix, 0, n - 1, m);
        printf("Перший і останній рядки були замінені місцями.\n");
    } else {
        printf("Один або обидва рядки не містять лише негативних елементів.\n");
    }

    // Виведення результату
    printf("Результуюча матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
