//!Этот код НЕ ОРИГИНАЛЬНЫЙ!!! Он был взят с другого моего кода: ForRybakova10102020 - именно этот код есть оригиналом, и все обстоятельства описаны там. Здесь я всего лишь хочу сказать, что этот код я изрядно переписал и дописал, а также полностью изменил структуру (теперь это не линейная программа с парой функций, а полностью процедурная программа) и полностью заточил под Линукс.

//!==========     Начало кода     ==========

#include <math.h>
#include <cstdio>
#include <iostream>
using namespace std;

void print(float *y, float x)
{
    int form;
    bool Prov = 1;
    do
    {
        cout << "Вы хотите вывести результат с форматированием (1) или без форматирования (0)? ";
        cin >> form;
        switch (form)
        {
        case 0:
            Prov = 1;
            cout << "Y = " << *y << " при X: " << x << "\n";
            break;
        case 1:
            Prov = 1;
            printf("Y = %.2f при X: %.8f\n", *y, x);
            break;
        default:
            cout << "Введено неправильное значение, повторите попытку.\n";
            Prov = 0;
            break;
        }
    } while (Prov == 0);
}
float f(float x, float n)
{
    float f = (pow((x + 1), n) - 1) / x;
    return f;
}
float count(float *y, float *n)
{
    float x1 = 1, x2 = 1, xt;
    while (f(x1, *n) > *y)
        x1 = x1 / 2;
    while (f(x2, *n) < *y)
        x2 = x2 * 2;
    while (x2 - x1 > 0.00001) //0.00001 - точность расчёта
    {
        xt = (x1 + x2) / 2;
        if (f(xt, *n) > *y)
            x2 = xt;
        else
            x1 = xt;
    }
    return xt;
}
void Start(float *y, float *n)
{
    cout << "Введите Y ";
    cin >> *y;
    cout << "и N(>1) ";
    cin >> *n;
}
int main()
{
    float y, n;
    Start(&y, &n);
    print(&y, count(&y, &n));
    return 0;
}

//!==========     Конец кода     ==========