#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon, term, sum;
    int n;

    // Введення значень x і epsilon
    printf("Введіть значення x (|x| < 1): ");
    scanf("%lf", &x);
    if (fabs(x) >= 1) {
        printf("Значення x повинно бути у межах (-1, 1).\n");
        return 1;
    }

    printf("Введіть значення epsilon (> 0): ");
    scanf("%lf", &epsilon);
    if (epsilon <= 0) {
        printf("Значення epsilon повинно бути більше 0.\n");
        return 1;
    }

    // Ініціалізація
    term = 1.0;  // Перший доданок ряду
    sum = term;  // Сума ряду
    n = 1;       // Початковий індекс

    // Цикл для обчислення суми
    while (fabs(term) >= epsilon) {
        term *= -x * x; // Наступний доданок (-x^2)^(n)
        sum += term;    // Додавання доданка до суми
        n++;
    }

    // Результат
    printf("Наближене значення суми: y = %.10f\n", sum);
    printf("Кількість доданків: %d\n", n);

    return 0;
}
