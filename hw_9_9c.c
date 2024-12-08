#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція для створення динамічного масиву
double** createMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Функція для вивільнення пам'яті
void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функція для виведення матриці
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Функція для знаходження рядків із найменшим за модулем елементом
int* findRowsWithMin(double** matrix, int rows, int cols, int* minRowCount) {
    double minVal = fabs(matrix[0][0]);
    int* minRows = (int*)malloc(rows * sizeof(int)); // Рядки, які потрібно видалити
    int count = 0;

    // Знаходимо найменший за модулем елемент
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(matrix[i][j]) < minVal) {
                minVal = fabs(matrix[i][j]);
            }
        }
    }

    // Знаходимо рядки, які містять цей елемент
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(matrix[i][j]) == minVal) {
                minRows[count++] = i;
                break;
            }
        }
    }

    *minRowCount = count;
    return minRows;
}

// Функція для видалення рядків
double** removeRows(double** matrix, int rows, int cols, int* rowsToRemove, int rowsToRemoveCount, int* newRows) {
    int newRowIndex = 0;
    double** newMatrix = createMatrix(rows - rowsToRemoveCount, cols);

    for (int i = 0; i < rows; i++) {
        int shouldRemove = 0;
        for (int j = 0; j < rowsToRemoveCount; j++) {
            if (i == rowsToRemove[j]) {
                shouldRemove = 1;
                break;
            }
        }
        if (!shouldRemove) {
            for (int j = 0; j < cols; j++) {
                newMatrix[newRowIndex][j] = matrix[i][j];
            }
            newRowIndex++;
        }
    }

    *newRows = rows - rowsToRemoveCount;
    return newMatrix;
}

int main() {
    int n, m;

    // Введення розмірів матриці
    printf("Введіть кількість рядків N: ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців M: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Розміри матриці повинні бути додатними.\n");
        return 1;
    }

    // Створення динамічного масиву
    double** matrix = createMatrix(n, m);

    // Введення елементів матриці
    printf("Введіть елементи матриці (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Виведення початкової матриці
    printf("\nПочаткова матриця:\n");
    printMatrix(matrix, n, m);

    // Знаходження рядків із мінімальним елементом
    int minRowCount;
    int* rowsToRemove = findRowsWithMin(matrix, n, m, &minRowCount);

    if (minRowCount > 0) {
        // Видалення рядків
        int newRows;
        double** newMatrix = removeRows(matrix, n, m, rowsToRemove, minRowCount, &newRows);

        // Вивільнення пам'яті для старої матриці
        freeMatrix(matrix, n);

        // Виведення нової матриці
        printf("\nМодифікована матриця:\n");
        printMatrix(newMatrix, newRows, m);

        // Вивільнення пам'яті для нової матриці
        freeMatrix(newMatrix, newRows);
    } else {
        printf("\nРядків для видалення не знайдено.\n");
    }

    // Вивільнення пам'яті
    free(rowsToRemove);

    return 0;
}
