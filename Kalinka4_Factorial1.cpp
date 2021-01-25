//*Эта прогнрамма считает факториал (до 16), введёный пользователем

#include <iostream>
using namespace std;

//Эта функция считает факториал
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Введите, какое число возводится в факториал (работает с числами только до 16): ";
    cin >> n;
    cout << "Результат: " << factorial(n) << ".\n";
    return 0;
}