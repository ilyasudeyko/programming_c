#include <stdio.h>
#include <limits.h>

// Функція для обробки файлів
void process_files(const char *fileF, const char *fileG, int n) {
    FILE *fF, *fG;
    int value, max, count = 0;

    // Відкриваємо файл F для читання
    fF = fopen(fileF, "r");
    if (fF == NULL) {
        printf("Не вдалося відкрити файл F.\n");
        return;
    }

    // Відкриваємо файл G для запису
    fG = fopen(fileG, "w");
    if (fG == NULL) {
        printf("Не вдалося відкрити файл G.\n");
        fclose(fF);
        return;
    }

    // Читання та обробка файлу F
    while (fscanf(fF, "%d", &value) == 1) {
        if (count % n == 0) {
            // Якщо починаємо нову групу, ініціалізуємо максимум
            max = INT_MIN;
        }

        // Оновлюємо максимум для поточної групи
        if (value > max) {
            max = value;
        }

        count++;

        // Якщо група повна, записуємо максимум у файл G
        if (count % n == 0) {
            fprintf(fG, "%d\n", max);
        }
    }

    // Якщо залишилися неповні групи, записуємо їх максимум
    if (count % n != 0) {
        fprintf(fG, "%d\n", max);
    }

    // Закриття файлів
    fclose(fF);
    fclose(fG);
}

int main() {
    int n;
    char fileF[100], fileG[100];

    // Введення значення n та імен файлів
    printf("Введіть ім'я файлу F: ");
    scanf("%s", fileF);

    printf("Введіть ім'я файлу G: ");
    scanf("%s", fileG);

    printf("Введіть значення n: ");
    scanf("%d", &n);

    // Обробка файлів
    process_files(fileF, fileG, n);

    printf("Файл G успішно створено.\n");

    return 0;
}
