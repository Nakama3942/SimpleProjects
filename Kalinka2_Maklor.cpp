//*Пользователь вводит натуральное число n, а программа просчитывает сумму по формуле 1 + 1/2^5 + .. + 1/n^5

#include <iostream>
#include <math.h>

using namespace std;

void form(double n)
{
    double S = 1, an = 1;
    for (n; n != 0; n--)
    {
        S = S + an;
        double b = pow(n - 1, 5) / pow(n, 5);
        an = an * b;
        cout << "N = " << n << "; S = " << S << ".\n";
    }
}
void poll(double *n)
{
    cout << "N = ";
    cin >> *n;
    cout << "\n";
}
int main()
{
    double n;
    poll(&n);
    form(n);
    return 0;
}
