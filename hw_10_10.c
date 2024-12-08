#include <stdio.h>
#include <stdlib.h>

// Структура для зберігання інформації про країну
typedef struct {
    char name[50];     // Назва країни
    double population; // Чисельність населення (у мільйонах)
    double area;       // Площа (у км²)
} Country;

// Функція для обчислення щільності населення
double calculateDensity(const Country* country) {
    return country->population / country->area;
}

// Основна функція
int main() {
    int n;

    printf("Введіть кількість країн: ");
    scanf("%d", &n);

    // Створення масиву країн
    Country* countries = (Country*)malloc(n * sizeof(Country));
    if (countries == NULL) {
        fprintf(stderr, "Помилка виділення пам'яті для масиву країн.\n");
        return EXIT_FAILURE;
    }

    // Введення даних про країни
    for (int i = 0; i < n; i++) {
        printf("Країна %d:\n", i + 1);
        printf("Назва: ");
        scanf("%s", countries[i].name);
        printf("Чисельність населення (у мільйонах): ");
        scanf("%lf", &countries[i].population);
        printf("Площа (у км²): ");
        scanf("%lf", &countries[i].area);
    }

    // Пошук країни з мінімальною щільністю населення
    int minDensityIndex = 0;
    double minDensity = calculateDensity(&countries[0]);

    for (int i = 1; i < n; i++) {
        double currentDensity = calculateDensity(&countries[i]);
        if (currentDensity < minDensity) {
            minDensity = currentDensity;
            minDensityIndex = i;
        }
    }

    // Виведення результату
    printf("\nКраїна з мінімальною щільністю населення:\n");
    printf("Назва: %s\n", countries[minDensityIndex].name);
    printf("Чисельність населення: %.2lf млн\n", countries[minDensityIndex].population);
    printf("Площа: %.2lf км²\n", countries[minDensityIndex].area);
    printf("Щільність населення: %.2lf осіб/км²\n", minDensity);

    // Звільнення пам'яті
    free(countries);

    return 0;
}
