#include <stdio.h>
#include <math.h>

// Функція eReLU(a, x)
double eReLU(double a, double x) {
    if (x < 0) {
        return a * (exp(x) - 1);
    } else {
        return 0;
    }
}

// Похідна функції eReLU(a, x)
double eReLU_derivative(double a, double x) {
    if (x < 0) {
        return a * exp(x);
    } else {
        return 0;
    }
}

int main() {
    double a, x;
    
    // Введення значень параметра a та змінної x
    printf("Введіть значення a: ");
    scanf("%lf", &a);
    
    printf("Введіть значення x: ");
    scanf("%lf", &x);
    
    // Обчислення значення функції та її похідної
    double f_value = eReLU(a, x);
    double f_derivative = eReLU_derivative(a, x);
    
    // Виведення результатів
    printf("eReLU(a, x) = %lf\n", f_value);
    printf("Похідна eReLU'(a, x) = %lf\n", f_derivative);
    
    return 0;
}
