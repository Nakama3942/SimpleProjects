//��� ���������� ������� ��������� (�� 16), ������� �������������

#include <stdio.h>
#include <Windows.h>

//��� ������� ������� ���������
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
	printf("�������, ����� ����� ���������� � ��������� (�������� � ������� ������ �� 16): ");
	scanf("%i", &n);
	printf("���������: %i .\n", factorial(n));
	system("pause");
	return 0;
}
