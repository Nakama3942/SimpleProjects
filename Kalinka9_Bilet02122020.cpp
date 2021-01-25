//*В среду, 02.12.2020, я здавал зачёт по БМТП (Базовым методологиям и технологиям программирования). Но для зачёта мы тянули билет, как на экзамене. В билете было 10 теоретических вопросов и 1 задание, в котором нужно написать код программы. Это задание звучит так: "Нужно сгенерировать миссивы N(5, 7) и M(4, 6), найти в каждом массиве наименьший элемент и его расположенние в массиве.". Этот код есть решением этого задания.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Следуюзая функция предназначена для генерации массива заданого размера, поиска наименьшего элемента в только что сгенерированном массиве и нахождения координат этого элемента в массиве.
void JobsWithMassiv(int x, int y)
{
    srand(time(NULL)); //Рандомизирую элементы массива зависимостью от времени
    int Massiv[x][y];  //Генерирую массив элементов
    int Adress[2];     //Массив, который предназначен для хранения координат наименьшего элемента
    int *Element1 = &Massiv[0][0], *Element2;
    //Генерирую каждый элемент массива и вывожу его на экран
    for (int j1 = 0; j1 < y; j1++)
    {
        for (int i1 = 0; i1 < x; i1++)
        {
            Massiv[i1][j1] = 10 + rand() % 89;
            cout << Massiv[i1][j1] << " ";
        }
        cout << "\n\n";
    }
    //Нахожу наименьший элемент
    for (int j2 = 0; j2 < y; j2++)
    {
        for (int i2 = 0; i2 < x; i2++)
        {
            //Выбираю следующий элемент по списку...
            if (i2 == x)
                Element2 = &Massiv[i2][j2 + 1];
            else
                Element2 = &Massiv[i2][j2];
            //... и сравниваю его с предыдущим
            if (*Element2 < *Element1)
                *Element1 = *Element2;
        }
    }
    //Нахожу и сохраняю координаты наименьшего элемента
    for (int j3 = 0; j3 < y; j3++)
    {
        for (int i3 = 0; i3 < x; i3++)
        {
            if (*Element1 == Massiv[i3][j3])
            {
                Adress[0] = i3;
                Adress[1] = j3;
            }
        }
    }
    //Вывожу информацию на экран
    cout << "Этот наименьший элемент равен числу " << *Element1 << "\n";
    cout << "А его координаты: " << Adress[0] + 1 << "х" << Adress[1] + 1 << "\n\n-----\n";
}
//Функция для вывода начальной информации
void Start(int x, int y)
{
    cout << "Сейчас мы сгенерируем массив размером " << x << "x" << y << ", найдём наименьшее число и его координаты в массиве: \n\n";
    JobsWithMassiv(x, y);
}
int main()
{
    Start(5, 7);
    Start(4, 6);
    cin.get();
    return 0;
}