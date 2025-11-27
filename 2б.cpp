#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Вычислить значение в соответствии с номером варианта. Предусмотреть
// возможность выбора функции f(x):sh(x), x^2 или e^x. Вывести на экран
// информацию о выполняемой ветви вычислений.
double f_sh(double x) {
    return sinh(x);
}

double f_square(double x) {
    return x * x;
}

double f_exp(double x) {
    return exp(x);
}

int main() {
    double x, y, b;
    int choice;
    
    
    printf("Выберите функцию f(x):\n");
    printf("1 - sh(x)\n");
    printf("2 - x^2\n");
    printf("3 - e^x\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    
    
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите y: ");
    scanf("%lf", &y);
    
    
    double (*f)(double);
    char* func_name;
    
    switch(choice) {
        case 1:
            f = f_sh;
            func_name = "sh(x)";
            break;
        case 2:
            f = f_square;
            func_name = "x^2";
            break;
        case 3:
            f = f_exp;
            func_name = "e^x";
            break;
        default:
            printf("Неверный выбор функции!\n");
            return 1;
    }
    
    printf("\nВыполняемые вычисления:\n");
    printf("f(x) = %s\n", func_name);
    printf("x = %.2f, y = %.2f\n", x, y);
    printf("x^2 + y = %.2f\n", x*x + y);
    
    
    if (x*x + y == 0) {
        printf("Ветвь: x^2 + y = 0\n");
        printf("Формула: sqrt(x) / y\n");
        if (x < 0) {
            printf("Ошибка: x отрицательный, нельзя вычислить sqrt(x)\n");
            return 1;
        }
        if (y == 0) {
            printf("Ошибка: деление на ноль!\n");
            return 1;
        }
        b = sqrt(x) / y;
        printf("Вычисление: sqrt(%.2f) / %.2f = %.2f / %.2f = %.4f\n", 
               x, y, sqrt(x), y, b);
    }
    else if (x*x + y < 0) {
        printf("Ветвь: x^2 + y < 0\n");
        printf("Формула: cos^3(y) - f(x)\n");
        double cos_y = cos(y);
        double f_x = f(x);
        b = pow(cos_y, 3) - f_x;
        printf("Вычисление: cos(%.2f)^3 - %s(%.2f) = %.2f^3 - %.2f = %.4f\n", 
               y, func_name, x, cos_y, f_x, b);
    }
    else {
        printf("Ветвь: иначе (x^2 + y > 0)\n");
        printf("Формула: sin(cos(2*f(x)))\n");
        double f_x = f(x);
        double inner = 2 * f_x;
        double cos_inner = cos(inner);
        b = sin(cos_inner);
        printf("Вычисление: sin(cos(2*%s(%.2f))) = sin(cos(2*%.2f)) = sin(cos(%.2f)) = sin(%.2f) = %.4f\n", 
               func_name, x, f_x, inner, cos_inner, b);
    }
    
    printf("\nРезультат: b = %.4f\n", b);
    
    return 0;
}