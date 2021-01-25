//*Пользовател вводит натуральное число n и действительное x, а программа просчитывает сумму по формуле x + x^2/2! + .. + x^n/n!

#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
double form(int n, int x)
{
    double S = x, an = x;
    for (n; n != 1; n--)
    {
        S = S + an;
        double xn = pow(x, n);
        int n1 = n - 1;
        int fact_n1 = factorial(n1);
        int fact_n = factorial(n);
        double x_n1 = pow(x, n1);
        double b = (xn * fact_n1) / (fact_n * x_n1);
        an = an * b;
    }
    S = S + an + x;
    return S;
}
double poll()
{
    double n, x;
    cout << "N = ";
    cin >> n;
    cout << "X = ";
    cin >> x;
    cout << "\n";
    return form(n, x);
}
int main()
{
    double S = poll();
    cout << "S = " << S << ".\n";
    return 0;
}
