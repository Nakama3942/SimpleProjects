/*����� ������� ������ (���������), � ������� ��� �� �����, ���������
��� ���� ����������� �������; ������������� ������, ������ ���������
������ � ��������� ����������; �������� ��������� �� ������ 10 ���
��� ������� ������ (��� ���������� ��� � ���������), �������� ������
���������� � ��������� ������� � �������� ����� � ����������; ���������
����������� �=�(�) �� ����� ������� ��� ������ ������� ��������� (�
��������� � ����������� �����); ������� ����� ���������� (� ����������)
�������� � �������, ��������� �������� ����� ������, ������������
��������. ������� 3: ������: �����, ������; ���: ��������������;
�����������: � �����; �������: �� �����������; �����: ��������.*/

#include <Windows.h> //����� ��� ����������� �������� � ������� sleep
#include <stdio.h> //����� ��� ��������������� �����-������
#include <stdlib.h> //��������� ���������� � �������� �������
#include <time.h> //����� ��� ������� time � clock

//������� ������ ����������
void vyvod(float Massiv[], int Capacity) {
    for (int p = 0; p < Capacity; p++) {
		//������� ������ ��������� ��������� � ������, � ��������� ����� �� ���������
    	if (p % 8 != 0){
    		printf("|___%.3f__|", Massiv[p]);
		}
		else {
			printf("\n|___%.3f__|", Massiv[p]);
		}
    }
}

//������� ���������� ������� �����
void sort1(float Massiv[], int Capacity) {
	unsigned int Start_time = clock(); //��������� �����
	int shag = Capacity;
	while (shag > 0) {
		for (int n = 0; n < Capacity - shag; n++) {
			//��������� �������� � ��������� ������� �� ������ �����
			float *Menshee = &Massiv[n];
			float *Tekushee = &Massiv[n+shag];
			if (*Menshee > *Tekushee) {
				float Zamen = *Menshee;
				*Menshee = *Tekushee;
				*Tekushee = Zamen;
			}
		}
		shag /= 2;
	}
	unsigned int End_time = clock(); //�������� �����
	unsigned int Search_time = (End_time - Start_time); //������� �����
	printf("\n\n����� ������ = %i :\n", Capacity); //������� �������� ������
	vyvod(Massiv, Capacity); //������ ��������������� ������
	printf("\n����� ����������: %u", Search_time); //������ ����� ����������
}

//������� ���������� ������� ������
void sort2(float Massiv[], int Capacity) {
	unsigned int Start_time = clock(); //��������� �����
	
	for (int Prosmotr = 0; Prosmotr < Capacity; Prosmotr++){
		float *Menshee = &Massiv[Prosmotr];
		//��������� ������ ����� � ������, � � ����� ������ ������ ������ ����������
		//�� ������ ��������� ���� ����� ���������� �� ������ ���������
		for (int Prosm = Prosmotr + 1; Prosm < Capacity; Prosm++) {
			float *Tekushee = &Massiv[Prosm];
			if (*Menshee > *Tekushee) {
				float Zamen = *Menshee;
				*Menshee = *Tekushee;
				*Tekushee = Zamen;
			}
		}
	}
	unsigned int End_time = clock(); //�������� �����
	unsigned int Search_time = (End_time - Start_time); //������� �����
	printf("\n\n����� ������ = %i :\n", Capacity); //������� �������� ������
	vyvod(Massiv, Capacity); //������ ��������������� ������
	printf("\n����� ����������: %u", Search_time); //������ ����� ����������
}

//������� ������
int BinarySearch(float Massiv[], float SearchEl, int Left, int Right) {
	if (Right >= Left) {
		//������ ��������, � ������� ���� ������� ����� � ������ ��� ����� �������� �������
		//� ����� ������ ��������� ����� �������� ��� -1
		int mid = (Right + Left) / 2;
		if (Massiv[mid] == SearchEl) {
			return mid;
		}
		if (Massiv[mid] > SearchEl) {
			return BinarySearch(Massiv, SearchEl, Left, mid - 1);
		}
		if (Massiv[mid] < SearchEl) {
			return BinarySearch(Massiv, SearchEl, mid + 1, Right);
		}
	}
	return -1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    printf("\n\n\n__________\n\n\n��������� ���������, ���������� �������� � ������ ���������� ��������� � �������\n\n\n__________\n\n\n");

	int Capacity, Vybor_sort, Vyzov = 0;
	boolean Vyhod = 1;
	//���������, ��� ����� ������������ ������������� ������
	printf("�������� ����� ����������: �����(1) ��� �������(2): ");
	do {
		fflush(stdin);
		scanf("%i", &Vybor_sort);
		switch (Vybor_sort) {
		case 1:
			Vyhod = 0;
			Vyzov = 1;
			break;
		case 2:
			Vyhod = 0;
			break;
		default:
			Vyhod = 1;
			printf("������� ������������ ��������. ��������� �������: ");
			break;
		}
	} while (Vyhod == 1);

	/*������� ����, ��� ����� �������������� 10 ��� ������� � ������������� ��������� �������.
	� ����� ���� ����������, ����� ������ ����� ����� ������������ � �������� ������� ������.*/
	for (int p = 0; p < 10; p++) {
		srand(time(NULL)); //���� ������� ����� ��� ������� �������

		//������ �������� ������, ������� ����� �������� �� 2, 4, 8, 16, 32, 64, 128, 256 ��� 512 ���������
		Capacity = 10 + rand() % 1000;
		for (int z = 2; z < Capacity * 2; z = z * 2) {
			if (Capacity < z) {
				Capacity = z;
			}
		}
		float Massiv[Capacity];

		//��������� ��� ������� �������� ��� ��������
		for (int i = 0; i < Capacity; i++) {
			float element = 10000 + rand() % 17342561;
			Massiv[i] = element / 1000;
		}
		//������ �� ����� ��������� ������ �������
		printf("��� ���������� ��������� %i, ������ ������:\n", Capacity);
		vyvod(Massiv, Capacity);

		Sleep(500); //������ ���������� ����� ����������� (���������� � �������� ����� �������
		//�������� ������ � ����������� �� ���������� ������������� ������
		if (Vyzov == 1) {
			sort1(Massiv, Capacity);
		}
		else {
			sort2(Massiv, Capacity);
		}
		if (p < 9) {
			printf("\n\n\n������ ���������\n\n\n");
		}
		Sleep(1500); //��������� ����� ��������� ������� �������

		//������� ����� � �����������: ������������ ������ �����, ������� ����� �����...
		if (p == 9) {
			printf("\n\n��������� ��������� 10 ���. ������� � ��������� ������� ����� ������ ��� �����: ");
			float SearchEl;
			fflush(stdin);
			scanf("%f", &SearchEl);
			//... � ���������� ������� ������ ��������������� ����� � �������
			int SearchInFunc = BinarySearch(Massiv, SearchEl, 0, Capacity - 1);
			printf("���� ������� ��������� �� %i �����.", SearchInFunc); //������ ����� ��������
		}
	}
	//�������� ���������
    printf("\n\n\n__________\n\n\n��������� ���������\n\n\n__________");
    system("pause");
    return 0;
}
