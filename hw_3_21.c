#include <stdio.h>
#include <math.h>

int main() {
    double x, y, z, R, distance_squared;

    // Введення координат точки та радіусу кулі
    printf("Введіть координати точки (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    printf("Введіть радіус кулі (R): ");
    scanf("%lf", &R);
    
    // Обчислення відстані від точки до центру кулі
    distance_squared = x * x + y * y + z * z;

    // Перевірка умови належності точки кулі
    if (distance_squared <= R * R) {
        printf("Точка належить кулі.\n");
    } else {
        printf("Точка не належить кулі.\n");
    }
    
    return 0;
}
