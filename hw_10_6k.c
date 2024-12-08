#include <stdio.h>
#include <stdlib.h>

// Структура для координат вершини
typedef struct {
    int x;
    int y;
} Point;

// Структура для багатокутника
typedef struct {
    int numVertices; // Кількість вершин
    Point* vertices; // Масив координат вершин
} Polygon;

// Функція для створення багатокутника
Polygon createPolygon(int numVertices) {
    Polygon polygon;
    polygon.numVertices = numVertices;
    polygon.vertices = (Point*)malloc(numVertices * sizeof(Point));
    if (polygon.vertices == NULL) {
        fprintf(stderr, "Помилка виділення пам'яті для вершин багатокутника.\n");
        exit(EXIT_FAILURE);
    }
    return polygon;
}

// Функція для введення багатокутника
void inputPolygon(Polygon* polygon) {
    printf("Введіть координати %d вершин:\n", polygon->numVertices);
    for (int i = 0; i < polygon->numVertices; i++) {
        printf("Вершина %d (x, y): ", i + 1);
        scanf("%d %d", &polygon->vertices[i].x, &polygon->vertices[i].y);
    }
}

// Функція для виведення багатокутника
void printPolygon(const Polygon* polygon) {
    printf("Багатокутник з %d вершинами:\n", polygon->numVertices);
    for (int i = 0; i < polygon->numVertices; i++) {
        printf("Вершина %d: (%d, %d)\n", i + 1, polygon->vertices[i].x, polygon->vertices[i].y);
    }
}

// Функція для звільнення пам'яті багатокутника
void freePolygon(Polygon* polygon) {
    free(polygon->vertices);
    polygon->vertices = NULL;
    polygon->numVertices = 0;
}

// Основна функція
int main() {
    int numVertices;

    printf("Введіть кількість вершин багатокутника: ");
    scanf("%d", &numVertices);

    // Створення багатокутника
    Polygon polygon = createPolygon(numVertices);

    // Введення та виведення багатокутника
    inputPolygon(&polygon);
    printPolygon(&polygon);

    // Звільнення пам'яті
    freePolygon(&polygon);

    printf("Програма завершилася успішно.\n");
    return 0;
}
