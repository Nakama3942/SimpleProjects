#include <iostream>
using namespace std;

void Results(int NumMass, int *MyMassiv)
{
    //Вывожу окончательный результат
    cout << "\nРезультат: Новый отсортированный массив: ";
    cout << MyMassiv[0];
    for (int t = 1; t < NumMass; t++)
    {
        cout << ", " << MyMassiv[t];
    }
    cout << ". Сортировка завершена.\n";
}
int *SortMass(bool Nastroy, int NumMass, int *MyMassiv)
{
    int MassElement1 = MyMassiv[0], MassElement2;
    cout << "\n\n";
    //Программа начинает процесс сортировки
    for (int k = 0; k < NumMass; k++)
    {
        //этот цикл находит самое большое число
        for (int i = k; i < NumMass; i++)
        {
            //Присваиваю второму числу значение элемента массива, который соответсвует номеру счётчика цикла
            MassElement2 = MyMassiv[i];
            //Если второе число больше первого, оно записывается в первое
            if (MassElement1 < MassElement2)
            {
                MassElement1 = MassElement2;
            }
            //Следующий текст выводится только если пользователь этого хочет
            if (Nastroy == 1)
            {
                cout << "Проверка работы 1:первый элемент: " << MassElement1 << "; Второй: " << MassElement2 << ".\n";
            }
        }
        //Следующий текст выводится только если пользователь этого хочет
        if (Nastroy == 1)
        {
            cout << "Смена режима проверки...\n";
        }
        //Этот цикл меняет это число местами с элементом, номер которого соответствует основному циклу
        for (int n = k; n < NumMass; n++)
        {
            //После нахождения большого числа, на его место записывается элемент, который соответствует счётчику основного цикла, а это число записывается на место с номером счётчика основного цикла
            if (MassElement1 == MyMassiv[n])
            {
                MyMassiv[n] = MyMassiv[k];
                MyMassiv[k] = MassElement1;
            }
            //Следующий текст выводится только если пользователь этого хочет
            if (Nastroy == 1)
            {
                cout << "Проверка работы 2: первый элемент: " << MassElement1 << "; Второй: " << MyMassiv[n] << ".\n";
            }
        }
        //Сбрасываю первое число на минимальное, чтобы цикл правильно работал
        MassElement1 = -2147483647;
        //Выводится промежуточный результат текущего этапа сортировки, если пользователь этого хочет
        if (Nastroy == 1)
        {
            cout << "\nМассив: ";
            cout << MyMassiv[0];
            for (int m = 1; m < NumMass; m++)
            {
                cout << ", " << MyMassiv[m];
            }
            cout << ". Конец этого этапа.\n\n\n";
        }
        //Это и весь цикл, дальше он повторяется/заканчивается
    }
    return MyMassiv;
}
bool Settings()
{
    //Спрашиваю у пользователя, хочет ли он видеть, как программа сортирует массив
    int ProvNastroy;
    bool Nastroy, Prov_ProvNastroy = 1;
    cout << "\n\nМаленькая настроечка: Хотите ли вы видеть процесс сортировки (нужно при настройке программы) (1/0)? ";
    do
    {
        cin >> ProvNastroy;
        switch (ProvNastroy)
        {
        case 1:
            Prov_ProvNastroy = 1;
            Nastroy = 1;
            break;
        case 0:
            Prov_ProvNastroy = 1;
            Nastroy = 0;
            break;
        default:
            Prov_ProvNastroy = 0;
            cout << "Введено неправильное значение, повторите попытку: ";
            break;
        }
    } while (Prov_ProvNastroy == 0);
    return Nastroy;
}
void GenMass()
{
    //Начинаю диалог с пользователем
    cout << "\n\nЭто программа для сортировки массивов.\n\n\n";
    cin.get();
    cout << "\n\nВ программе используются переменные типа int, которые имеют размер 4 байта (32 бита),\nпоэтому минимальное значение вводимиого элемента -2 147 483 648, а максимальное\n2 147 483 647. Просьба - не вводите каждый элемент массива больше/меньше указанного!\nИ ещё: Лучше в программе не сортировать массивы, в которых больше 100 элементов.\n\n";
    //Пользователь вводит размер массива
    cout << "Укажите количество элементов вашего массива: ";
    int NumMass;
    cin >> NumMass;
    //Создаю массив
    int MyMassiv[NumMass];
    //В зависимости от размера миссива, пользователь вводит указанное им количество элементов массива
    for (int p = 0; p < NumMass; p++)
    {
        cout << "\nВведите " << p + 1 << " число: ";
        cin >> MyMassiv[p];
    }
    Results(NumMass, SortMass(Settings(), NumMass, MyMassiv));
}
int main()
{
    GenMass();
    return 0;
}