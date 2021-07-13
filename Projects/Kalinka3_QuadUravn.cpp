//*Это программа, которая считает квадратные уравнения

#include <iostream>
#include <math.h>
using namespace std;

void f(int *a, int *b, int *c)
{
    int d;
    float x1, x2;
    if (*a < 0)
        cout << "Уравнение вырожденное.\n";
    else
    {
        d = (*b * *b) - (4 * *a * *c);
        if (d < 0)
            cout << "Действительных корней не существует.\n";
        else if (d == 0)
        {
            x1 = -*b / (2 * *a);
            cout << "Так как D = 0, => X1 = X2 = " << x1 << "\n";
        }
        else if (d > 0)
        {
            x1 = (-*b + sqrt(d)) / (2 * *a);
            x2 = (-*b - sqrt(d)) / (2 * *a);
            cout << "X1 = " << x1 << "; X2 = " << x2 << "\n";
        }
    }
}
void poll(int *a, int *b, int *c)
{
    cout << "Решение квадратных корней.\nВведите значение A: ";
    cin >> *a;
    cout << "Введите значение B: ";
    cin >> *b;
    cout << "Введите значение C: ";
    cin >> *c;
}
int main()
{
    int a, b, c;
    poll(&a, &b, &c);
    f(&a, &b, &c);
    return 0;
}
