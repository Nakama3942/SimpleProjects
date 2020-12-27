//Это доработка девятой программы, где пользователь сам задаёт количество массивов и их размерность

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

void JobsWithMassiv(int x, int y) {
	srand(time(NULL));
	int Massiv[x][y];
	int Adress[2];
	int *Element1 = &Massiv[0][0], *Element2;

	for (int j1 = 0; j1 < y; j1++) {
		for (int i1 = 0; i1 < x; i1++) {
			Massiv[i1][j1] = 10 + rand() % 89;
			cout << Massiv[i1][j1] << " ";
		}
		cout << "\n\n";
	}
	
	for (int j2 = 0; j2 < y; j2++) {
		for (int i2 = 0; i2 < x; i2++) {
			if (i2 == x) Element2 = &Massiv[i2][j2 + 1];
			else Element2 = &Massiv[i2][j2];
			
			if (*Element2 < *Element1) *Element1 = *Element2;
		}
	}
	
	for (int j3 = 0; j3 < y; j3++) {
		for (int i3 = 0; i3 < x; i3++) {
			if (*Element1 == Massiv[i3][j3]) {
				Adress[0] = i3;
				Adress[1] = j3;
			}
		}
	}

	cout << "Этот наименьший элемент равен числу " << *Element1 << "\n";
	cout << "А его координаты: " << Adress[0] + 1 << "х" << Adress[1] + 1 << "\n\n-----\n";
}

void Start(int j) {
	int x, y;
	cout << "\n\nДля массива " << j + 1 << " введите его размерность: количество элементов в строке и количество строк:\n";
	cin >> x;
	cin >> y;
	cout << "\n\nСейчас мы сгенерируем массив размером " << x << "x" << y << ", найдём наименьшее число и его координаты в массиве: \n\n";
	JobsWithMassiv(x, y);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Col;
	cout << "Введите количество массивов: ";
	cin >> Col;
	for (int i = 0; i < Col; i++) Start(i);
	system("pause");
}
