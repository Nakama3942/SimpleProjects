//Эта прогнрамма считает факториал (до 16), введёный пользователем

#include <stdio.h>
#include <Windows.h>

//Эта функция считает факториал
int factorial(int n) { //
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main () {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	printf("Введите, какое число возводится в факториал (работает с числами только до 16): ");
	scanf("%i", &n);
	printf("Результат: %i .\n", factorial(n));
	system("pause");
	return 0;
}
