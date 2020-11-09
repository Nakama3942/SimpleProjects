//Пользовател вводит натуральное число n и действительное x, а программа
//просчитывает сумму по формуле x + x^2/2! + .. + x^n/n!

#include <stdio.h>
#include <math.h>

double n;
double x;

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	double S = x;
	printf("N = ");
	scanf("%lf", &n);
	printf("X = ");
	scanf("%lf", &x);
	double an = x;
	printf("\n");
	for (n; n != 1; n--) {
		S = S + an;

		double xn = pow(x, n);
		int n1 = n - 1;
		int fact_n1 = factorial(n1);
		int fact_n = factorial(n);
		double x_n1 = pow(x, n1);

		double b = (xn * fact_n1) / (fact_n * x_n1);

		an = an * b;
	}
	S = S  + an + x;
	printf("S = %.16lf.\n", S);
	system("pause");
	return 0;
}
