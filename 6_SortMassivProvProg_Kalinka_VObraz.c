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
			printf("�������� ������ 1: ������ �������: %i; ������: %i .\n", MassElement1, MassElement2);
		}
		printf("����� ������ ��������...\n");
		for (n = k; n < NumMass; n++) {
			if (MassElement1 == MyMassiv[n]) {
				MyMassiv[n] = MyMassiv[k];
				MyMassiv[k] = MassElement1;
			}
			printf("�������� ������ 2: ������ �������: %i; ������: %i .\n", MassElement1, MyMassiv[n]);
		}
		MassElement1 = -2000;
		printf("\n������: ");
		for (m = 0; m < NumMass; m++) {
			printf("%i, ", MyMassiv[m]);
		}
		printf(". ����� ����� �����.\n\n\n\n");
	}
	printf("\n\n���������: ����� ��������������� ������: ");
	for (m = 0; m < NumMass; m++) {
		printf("%i, ", MyMassiv[m]);
	}
	printf("\n��������� ���������. ");
	system("pause");
	return 0;
}
