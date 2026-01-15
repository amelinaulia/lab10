#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

    
double f1(double x) {
    return x<= 3 ? x*x - 3 *x + 9 : (x>= 3 && x <= 5 ? 1 : x*x*x + 3);
}

double f2(double x) {
    return x * e(sin(x * x));
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    double x, a, b;
    int c;
    char r;

    do {
        printf("\n1-F1 2-F2 3-* 4-кв 5-2+ 6-все 0-выход: ");
        scanf("%d", &c);
        if (!c) break;

        printf("x: ");
        scanf("%lf", &x);

        a = f1(x);
        b = f2(x);

        printf("F1=%.3lf F2=%.3lf\n", a, b);

        if (c == 1 || c >= 3) printf("F1=%.3lf\n", a);
        if (c == 2 || c >= 3) printf("F2=%.3lf\n", b);
        if (c == 3 || c == 6) printf("Произведение: %.3lf\n", a * b);
        if (c == 4 || c == 6) printf("Разность квадратов: %.3lf\n", a * a - b * b);
        if (c == 5 || c == 6) printf("Удвоенная сумма: %.3lf\n", 2 * (a + b));

        printf("Продолжить? (y/n): ");
        scanf(" %c", &r);
    } while (r == 'y' || r == 'Y');

    return 0;
}