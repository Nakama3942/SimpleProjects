/*Эта программа сортирует массивы. Достаточно всего лишь переписать масив
и в NumMass указать, сколько вы написали элементов в массив. Если вы не хотите
смотреть процесс сортировки - просто закомментируйте 20, 22, 28, 31-35 строки*/

#include <stdio.h>
#include <Windows.h>
#define NumMass 13

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int MyMassiv[NumMass] = { 3, 2, 9, 7, 14, 239, 814, -17, -1984, 0, 1, -2, 54 };
	int i, k, n, m, o = NumMass, MassElement1 = MyMassiv[0], MassElement2;
	for (k = 0; k < NumMass; k++) {
		for (i = k; i < NumMass; i++) {
			MassElement2 = MyMassiv[i];
			if (MassElement1 < MassElement2) {
				MassElement1 = MassElement2;
			}
			printf("Проверка работы 1: первый элемент: %i; Второй: %i .\n", MassElement1, MassElement2);
		}
		printf("Смена режима проверки...\n");
		for (n = k; n < NumMass; n++) {
			if (MassElement1 == MyMassiv[n]) {
				MyMassiv[n] = MyMassiv[k];
				MyMassiv[k] = MassElement1;
			}
			printf("Проверка работы 2: первый элемент: %i; Второй: %i .\n", MassElement1, MyMassiv[n]);
		}
		MassElement1 = -2000;
		printf("\nМассив: ");
		for (m = 0; m < NumMass; m++) {
			printf("%i, ", MyMassiv[m]);
		}
		printf(". Конец этого этапа.\n\n\n\n");
	}
	printf("\n\nРезультат: Новый отсортированный массив: ");
	for (m = 0; m < NumMass; m++) {
		printf("%i, ", MyMassiv[m]);
	}
	printf("\nСортровка завершена. ");
	system("pause");
	return 0;
}
