/*Это новая программа, которая сама генерирует объём массива, генерирует
его значения, сортирует его, делает это десять раз, имеет 2 метода
сортировки, который выбирает пользватель, а в конце ещё из последнего
массива пользовательможет найти место данного элемента в массиве. Вот
само задание:
===
Нужно создать массив (динамично), и вывести его на экран, используя
при этом собственную функцию; Отсортировать массив, выбрав указанные
методы и параметры сортировки; Запуская программу не меньше 10 раз
для каждого метода (или предвидеть это в программе), задавать разное
количество Н элементов массива и получить время Т сортировки; построить
зависимость Т=Ф(Н) на одном графике для разных методов сортровки (в
табличном и графическом видах); Сделать поиск указанного (с клавиатуры)
элемента в массиве, используя укзанный метод поиска, относительно
варианта. Вариант 3: Методы: Шелла, выбора; Тип: действительные;
Направление: с конца; Порядок: по возрастанию; Поиск: бинарный.
===
Всё задание выполнено в этом коде.*/

#include <Windows.h> //Нужна для подключения русского и функции sleep
#include <stdio.h> //Нужна для форматированого ввода-вывода
#include <stdlib.h> //Подключаю библиотеку с функцией рандома
#include <time.h> //Нужна для функции time и clock

//Функция вывода результата
void vyvod(float Massiv[], int Capacity) {
	for (int p = 0; p < Capacity; p++) {
		//Текущие восемь элементов выводятся в строку, а следующие сношу на следующую
    		if (p % 8 != 0){
    			printf("|___%.3f__|", Massiv[p]);
		}
		else {
			printf("\n|___%.3f__|", Massiv[p]);
		}
	}
}

//Функция сортировки методом Шелла
void sort1(float Massiv[], int Capacity) {
	unsigned int Start_time = clock(); //Начальное время
	int shag = Capacity;
	while (shag > 0) {
		for (int n = 0; n < Capacity - shag; n++) {
			//Сравниваю элементы и выставляю меньший на первое место
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
	unsigned int End_time = clock(); //Конечное время
	unsigned int Search_time = (End_time - Start_time); //Искомое время
	printf("\n\nНовый массив = %i :\n", Capacity); //Начинаю выводить массив
	vyvod(Massiv, Capacity); //Вывожу отсортированный массив
	printf("\nВремя сортировки: %u", Search_time); //Вывожу время сортировки
}

//Функция сортировки методом выбора
void sort2(float Massiv[], int Capacity) {
	unsigned int Start_time = clock(); //Начальное время
	
	for (int Prosmotr = 0; Prosmotr < Capacity; Prosmotr++){
		float *Menshee = &Massiv[Prosmotr];
		//Сравниваю первое число с каждым, и в конце первым должно стоять наименьшее
		//На каждый следующий круг будет оставаться всё меньше элементов
		for (int Prosm = Prosmotr + 1; Prosm < Capacity; Prosm++) {
			float *Tekushee = &Massiv[Prosm];
			if (*Menshee > *Tekushee) {
				float Zamen = *Menshee;
				*Menshee = *Tekushee;
				*Tekushee = Zamen;
			}
		}
	}
	unsigned int End_time = clock(); //Конечное время
	unsigned int Search_time = (End_time - Start_time); //Искомое время
	printf("\n\nНовый массив = %i :\n", Capacity); //Начинаю выводить массив
	vyvod(Massiv, Capacity); //Вывожу отсортированный массив
	printf("\nВремя сортировки: %u", Search_time); //Вывожу время сортировки
}

//Функция поиска
int BinarySearch(float Massiv[], float SearchEl, int Left, int Right) {
	if (Right >= Left) {
		//Нахожу половину, в которой есть искомое число и каждый раз сужаю половину пополам
		//В конце должен вывестись номер элемента или -1
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
    
	printf("\n\n\n__________\n\n\nПРОГРАММА ГЕНЕРАЦИИ, СОРТИРОВКИ МАССИВОВ И ПОИСКА ГЕОЛОКАЦИИ ЭЛЕМЕНТОВ В МАССИВЕ\n\n\n__________\n\n\n");

	int Capacity, Vybor_sort, Vyzov = 0;
	boolean Vyhod = 1;
	//Спрашиваю, как хочет пользователь отсортировать массив
	printf("Выберите режим сортировки: Шелла(1) или выбором(2): ");
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
			printf("Введено неправильное значение. Повторите попытку: ");
			break;
		}
	} while (Vyhod == 1);

	/*Начинаю цикл, где будут генерироваться 10 раз массивы и сортироваться выбранным методом.
	В конце цикл спрашивает, какой элемнт хочет найти пользователь и вызывает функцию поиска.*/
	for (int p = 0; p < 10; p++) {
		srand(time(NULL)); //Беру текущее время для функции рандома

		//Создаю рандомно массив, который будет состоять из 2, 4, 8, 16, 32, 64, 128, 256 или 512 элементов
		Capacity = 10 + rand() % 1000;
		for (int z = 2; z < Capacity * 2; z = z * 2) {
			if (Capacity < z) {
				Capacity = z;
			}
		}
		float Massiv[Capacity];

		//Генерирую для каждого элемента своё значение
		for (int i = 0; i < Capacity; i++) {
			float element = 10000 + rand() % 17342561;
			Massiv[i] = element / 1000;
		}
		//Вывожу на экран начальный состав массива
		printf("При количестве элементов %i, старый массив:\n", Capacity);
		vyvod(Massiv, Capacity);

		Sleep(500); //Ожидаю полсекунды перед сортировкой (измеряется в тысячных долях секунды
		//Сортирую массив в зависимости от выбранного пользователем метода
		if (Vyzov == 1) {
			sort1(Massiv, Capacity);
		}
		else {
			sort2(Massiv, Capacity);
		}
		if (p < 9) {
			printf("\n\n\nПОВТОР ПРОГРАММЫ\n\n\n");
		}
		Sleep(1500); //Заставляю ждать программу полторы секунды

		//Начинаю часть с сортировкой: пользователь вводит число, которое хочет найти...
		if (p == 9) {
			printf("\n\nПрограмма выполнена 10 раз. Давайте в последнем массиве найдём нужное Вам число: ");
			float SearchEl;
			fflush(stdin);
			scanf("%f", &SearchEl);
			//... и вызывается функция поиска местонахождения числа в массиве
			int SearchInFunc = BinarySearch(Massiv, SearchEl, 0, Capacity - 1);
			printf("Этот элемент находится на %i месте.", SearchInFunc); //Вывожу номер элемента
		}
	}
	//Завершаю программу
	printf("\n\n\n__________\n\n\nПРОГРАММА ВЫПОЛНЕНА\n\n\n__________");
	system("pause");
	return 0;
}
