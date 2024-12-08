#include <stdio.h>
#include <stdlib.h>

// Функція для створення матриці заданих розмірів
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Помилка виділення пам'яті для матриці.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Помилка виділення пам'яті для рядка матриці.\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Функція для введення даних в матрицю
void inputMatrix(int** matrix, int rows, int cols) {
    printf("Введіть елементи матриці (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Функція для звільнення пам'яті, виділеної для матриці
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функція для створення та заповнення матриці суми
void sumMatrices(int*** matrices, int numMatrices, int rows, int cols, int** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < numMatrices; k++) {
                result[i][j] += matrices[k][i][j];
            }
        }
    }
}

// Основна функція
int main() {
    int numMatrices, rows, cols;

    printf("Введіть кількість матриць: ");
    scanf("%d", &numMatrices);
    printf("Введіть розміри матриць (рядки та стовпці): ");
    scanf("%d %d", &rows, &cols);

    // Виділення пам'яті для масиву матриць
    int*** matrices = (int***)malloc(numMatrices * sizeof(int**));
    if (matrices == NULL) {
        fprintf(stderr, "Помилка виділення пам'яті для масиву матриць.\n");
        return EXIT_FAILURE;
    }

    // Введення кожної матриці
    for (int i = 0; i < numMatrices; i++) {
        printf("Матриця %d:\n", i + 1);
        matrices[i] = createMatrix(rows, cols);
        inputMatrix(matrices[i], rows, cols);
    }

    // Створення та обчислення матриці суми
    int** resultMatrix = createMatrix(rows, cols);
    sumMatrices(matrices, numMatrices, rows, cols, resultMatrix);

    // Виведення матриці суми
    printf("Матриця суми:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // Очищення пам'яті
    for (int i = 0; i < numMatrices; i++) {
        freeMatrix(matrices[i], rows);
    }
    free(matrices);
    freeMatrix(resultMatrix, rows);

    printf("Програма завершилася успішно.\n");
    return 0;
}
