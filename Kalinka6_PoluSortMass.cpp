//*Эта программа сортирует массивы. Достаточно всего лишь переписать масив и в NumMass указать, сколько вы написали элементов в массив. Если вы не хотите смотреть процесс сортировки - просто закомментируйте 20, 22, 28, 31-35 строки, и ещё - не вводите в массив переменные больше 2 000 000

#include <iostream>
#define NumMass 13
using namespace std;

int main()
{
    int MyMassiv[NumMass] = {3, 2, 9, 7, 14, 239, 814, -17, -1984, 0, 1, -2, 54};
    int MassElement1 = MyMassiv[0], MassElement2;
    for (int k = 0; k < NumMass; k++)
    {
        for (int i = k; i < NumMass; i++)
        {
            MassElement2 = MyMassiv[i];
            if (MassElement1 < MassElement2)
            {
                MassElement1 = MassElement2;
            }
            cout << "Проверка работы 1: первый элемент: " << MassElement1 << "; Второй: " << MassElement2 << ".\n";
        }
        cout << "Смена режима проверки...\n";
        for (int n = k; n < NumMass; n++)
        {
            if (MassElement1 == MyMassiv[n])
            {
                MyMassiv[n] = MyMassiv[k];
                MyMassiv[k] = MassElement1;
            }
            cout << "Проверка работы 2: первый элемент: " << MassElement1 << "; Второй: " << MyMassiv[n] << ".\n";
        }
        MassElement1 = -2000000;
        cout << "\nМассив:";
        for (int m = 0; m < NumMass; m++)
        {
            cout << " " << MyMassiv[m];
        }
        cout << ". Конец этого этапа.\n\n\n\n";
    }
    cout << "\n\nРезультат: Новый отсортированный массив: ";
    for (int t = 0; t < NumMass; t++)
    {
        cout << MyMassiv[t];
    }
    cout << "\nСортровка завершена.\n";
    return 0;
}
