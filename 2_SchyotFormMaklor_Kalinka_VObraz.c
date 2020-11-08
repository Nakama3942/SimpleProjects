//Пользователь вводит натуральное число n, а программа просчитывает сумму по формуле 1 + 1/2^5 + .. + 1/n^5

#include <stdio.h>
#include <math.h>

double n;

int main() {
	double S = 1;
	printf("N = ");
	scanf("%lf", &n);
	double an = 1;
	printf("\n");
	for (n; n != 1; n--) {
		S = S + an;
		double b = pow(n - 1, 5) / pow(n, 5);
		an = an * b;
		printf("N = %.0lf; S = %.16lf.\n", n, S);
	} 
	system("pause");
	return 0;
}
