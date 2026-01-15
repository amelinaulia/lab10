#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

double sin_n(double x, int N);
double sin_eps(double x, double eps);

int main() {
    setlocale(LC_ALL, "RUS");

    double x, eps;
    int N;

    printf("¬ведите x: ");
    scanf("%lf", &x);

    printf("¬ведите N: ");
    scanf("%d", &N);

    printf("¬ведите eps: ");
    scanf("%lf", &eps);

    double sin_std = sin(x);

    printf("\n n(0,%d)\n", N);
    printf(" N |  sin_N  |   отклонение\n");
    printf("-----------------------------------\n");

    for (int k = 1; k <= N; k++) {
        double val = sin_n(x, k);


        printf("%2d | %7.4lf | %+12.4e\n", k, val, val - sin_std);
    }

    return 0;
}

double sin_n(double x, int N) {
    double sum = 0.0;

    for (int k = 1; k <= N; k++) {
        double term = pow(-1, k - 1) * pow(x, 2 * k - 1) / tgamma(2 * k);
        sum += term;
    }
    return sum;
}


double sin_eps(double x, double eps) {
    double sum = 0.0;
    double term = x;
    int k = 1;

    while (fabs(term) > eps) {
        sum += term;
        term *= -x * x / (2 * k * (2 * k + 1));
        k++;
    }

    return sum;
}
