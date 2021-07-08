//Решил немного попрактиковаться с потоками

#include <cmath>
#include <thread>
#include <iostream>
using namespace std;

long double e; //Экспонента (глобальная переменная)

//Функция, которая считая предел, стремящийся к миллиону
void exponential()
{
    for(int i = 1; i < 1000000; i++)
        e = pow((1. + (1. / i)), i);
}

int main()
{
    thread exponent(exponential);

    cout << "Please, wait...\n\n";

    exponent.join();

    cout << "Result: " << e;
    cin.get();
    return 0;
}
