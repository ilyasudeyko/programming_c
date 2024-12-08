#include <stdio.h>
#include <math.h>

// Функція softSign(x)
double softSign(double x) {
    return x / (1 + fabs(x));
}

// Похідна функції softSign(x)
double softSign_derivative(double x) {
    return 1 / pow((1 + fabs(x)), 2);
}

int main() {
    double x;
    
    // Введення значення x
    printf("Введіть значення x: ");
    scanf("%lf", &x);
    
    // Обчислення функції та її похідної
    double f_value = softSign(x);
    double f_derivative = softSign_derivative(x);
    
    // Виведення результатів
    printf("softSign(x) = %lf\n", f_value);
    printf("Похідна softSign'(x) = %lf\n", f_derivative);
    
    return 0;
}
