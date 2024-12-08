#include <stdio.h>
#include <string.h>

// Структура для зберігання даних про іграшку
typedef struct {
    char name[50];
    double price;
    int min_age;
    int max_age;
} Toy;

// Функція для пошуку двох іграшок, що відповідають віковим обмеженням і сумарній вартості
void find_toys(Toy toys[], int toy_count, int age, double max_sum, FILE *output_file) {
    int found = 0;

    // Перебираємо всі можливі пари іграшок
    for (int i = 0; i < toy_count - 1; i++) {
        for (int j = i + 1; j < toy_count; j++) {
            // Перевіряємо, чи підходять обидві іграшки для дітей віком x років
            if (toys[i].min_age <= age && toys[i].max_age >= age &&
                toys[j].min_age <= age && toys[j].max_age >= age) {
                
                // Перевіряємо, чи не перевищує їхня сумарна вартість Y гривень
                if (toys[i].price + toys[j].price <= max_sum) {
                    // Виводимо на консоль
                    printf("Знайдені іграшки: %s і %s, їхня сумарна вартість: %.2f грн\n",
                           toys[i].name, toys[j].name, toys[i].price + toys[j].price);
                    
                    // Записуємо у бінарний файл
                    fwrite(&toys[i], sizeof(Toy), 1, output_file);
                    fwrite(&toys[j], sizeof(Toy), 1, output_file);

                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("Не знайдено двох іграшок, що відповідають умовам.\n");
    }
}

int main() {
    FILE *input_file, *output_file;
    int toy_count = 0, age;
    double max_sum;
    Toy toys[100];  // Массив для зберігання іграшок

    // Відкриваємо вхідний файл для читання
    input_file = fopen("toys.txt", "r");
    if (input_file == NULL) {
        printf("Не вдалося відкрити файл toys.txt для читання.\n");
        return 1;
    }

    // Зчитуємо дані про іграшки з файлу
    while (fscanf(input_file, "%s %lf %d %d", toys[toy_count].name, &toys[toy_count].price, 
                  &toys[toy_count].min_age, &toys[toy_count].max_age) == 4) {
        toy_count++;
    }

    // Закриваємо вхідний файл
    fclose(input_file);

    // Відкриваємо вихідний бінарний файл для запису
    output_file = fopen("result.bin", "wb");
    if (output_file == NULL) {
        printf("Не вдалося відкрити файл result.bin для запису.\n");
        return 1;
    }

    // Введення віку дитини та максимальної суми
    printf("Введіть вік дитини: ");
    scanf("%d", &age);
    printf("Введіть максимальну суму (грн): ");
    scanf("%lf", &max_sum);

    // Пошук іграшок
    find_toys(toys, toy_count, age, max_sum, output_file);

    // Закриваємо вихідний файл
    fclose(output_file);

    return 0;
}
