#include <stdio.h>

int main() {
    double m, v, kinetic_energy;
    
    // Введення маси та швидкості
    printf("Введіть масу тіла (кг): ");
    scanf("%lf", &m);
    
    printf("Введіть швидкість тіла (м/с): ");
    scanf("%lf", &v);
    
    // Обчислення кінетичної енергії
    kinetic_energy = 0.5 * m * v * v;
    
    // Виведення результату
    printf("Кінетична енергія тіла: %.2f Дж\n", kinetic_energy);
    
    return 0;
}
