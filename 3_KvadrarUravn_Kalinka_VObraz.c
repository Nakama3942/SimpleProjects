//Это программа, которая считает квадратные уравнения

#include <stdio.h>
#include <math.h>
#include <Windows.h>

int a, b, c, d;
float x1, x2;

void f(int a, int b, int c) {
	if (a < 0) {
		printf("Уравнение вырожденное.\n");
	}
	else {
		d = (b * b) - (4 * a * c);
		if (d < 0) {
		printf("Действительных корней не существует.\n");
		}
		else if (d == 0) {
			x1 = -b / (2 * a);
			printf("Так как D = 0, => X1 = X2 = %.3f\n", x1);
		}
		else if (d > 0) {
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			printf("X1 = %.3f; X2 = %.3f\n", x1, x2);
		}
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Решение квадратных корней.\n");
	printf("Введите значение A: ");
	scanf("%i", &a);
	printf("Введите значение B: ");
	scanf("%i", &b);
	printf("Введите значение C: ");
	scanf("%i", &c);
	f(a, b, c);
	system("pause");
}
