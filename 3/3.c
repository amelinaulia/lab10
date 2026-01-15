#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <tgmath.h>

double cot_n(double x, int N);
double cot_eps(double x, double eps);

int main() {
    setlocale(LC_ALL, "RUS");

    double x, eps;
    int N;

    printf("Введите x: ");
    scanf("%lf", &x);

    printf("Введите N: ");
    scanf("%d", &N);

    printf("Введите eps: ");
    scanf("%lf", &eps);

    double cot_std = 1.0 / tan(x);

    printf("\n n(0,%d)\n", N);
    printf(" N |  cot_N  |   отклонение\n");
    printf("-----------------------------------\n");

    for (int k = 1; k <= N; k++) {
        double val = cot_n(x, k);
        printf("%2d | %7.4lf | %+12.4e\n", k, val, val - cot_std);
    }

    printf("\nЗначение через eps: %.10lf\n", cot_eps(x, eps));

    return 0;
}



double cot_n(double x, int N) {
    double sum = 1.0 / x;
    double sign = -1.0;

    for (int k = 1; k <= N; k++) {
        double coef;

        // коэффициенты ряда
        if (k == 1) coef = 1.0 / 3.0;
        else if (k == 2) coef = 1.0 / 45.0;
        else if (k == 3) coef = 2.0 / 945.0;
        else if (k == 4) coef = 2.0 / 4725.0;
        else
            break;

        double term = coef * pow(x, 2 * k - 1);
        sum += sign * term;
    }

    return sum;
}



double cot_eps(double x, double eps) {
    double sum = 1.0 / x;

    double term = x / 3.0;
    int k = 1;

    while (fabs(term) > eps) {
        sum -= term;

        k++;


        double coef;
        if (k == 1) coef = 1.0 / 3.0;
        else if (k == 2) coef = 1.0 / 45.0;
        else if (k == 3) coef = 2.0 / 945.0;
        else if (k == 4) coef = 2.0 / 4725.0;
        else break;

        term = coef * pow(x, 2 * k - 1);
    }

    return sum;
}
