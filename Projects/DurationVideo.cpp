//*Смотрел я видео на Ютубе и проматывал неинтересные моменты. И тогда я подумал: а что, если я сделаю программу, которая будет показывать 3 секунды, а потом 10 проматывать? Пока у меня нет нужных знаний и опыта для написания таких программ, но я могу пока написать программу, которая будет считать, сколько в результате я должен буду посмотреть видео, а сколько пропустить. Грубо говоря, есть у меня видео на 40 секунд, из них я просмотрю 3 секунды, 10 пропущу, 3 просмотрю, 10 пропущу, 3 просмотрю, 10 пропущу и остаётся одна секунда, которую я просмотрю. В итоге, из 40 секунд я просмотрю 10 секунд, а 30 не увижу. Я решил написать программу, которая будет считать это для видео с любой длительностью. Я проверил, как программа считает видео, длительностью до 5 часов. Ответы совпадаю со мною расчитанными.
//!Так как я недавно закончил курс по С++, я решил начать практиковаться с классами. После написания программы, я допереписал её, дописав в ней классы. Официально это моя первая программа в ООП!

#include <iostream>
using namespace std;

class Duration
{
public:
    int whole(int sec)
    {
        return sec /= 13;
    }
    int notwhole(int sec)
    {
        return sec %= 13;
    }
    void newDuration(int sec, int divSegm[2])
    {
        for (int p = 0; p < whole(sec); p++)
        {
            for (int n = 0; n < 3; n++)
                divSegm[0] += 1;
            for (int m = 0; m < 10; m++)
                divSegm[1] += 1;
        }
        if (notwhole(sec) <= 3)
            for (int n = 0; n < notwhole(sec); n++)
                divSegm[0] += 1;
        else
        {
            for (int n = 0; n < 3; n++)
                divSegm[0] += 1;
            for (int m = 0; m < (notwhole(sec) - 3); m++)
                divSegm[1] += 1;
        }
    }
};
class Count
{
public:
    int countInSec(int time[3])
    {
        for (int i = 0; i < time[0]; i++)
            time[1] += 60;
        for (int j = 0; j < time[1]; j++)
            time[2] += 60;
        return time[2];
    }
    void countOutSec(int newSec, int newTime[3])
    {
        newTime[2] = newSec % 60;     //Нахожу количество секунд в заданном времени, исключая часы и минуты
        newTime[1] = newSec / 60;     //Нахожу количество минут с часами без секунд
        newTime[0] = newTime[1] / 60; //Нахожу количество часов
        newTime[1] %= 60;             //Нахожу чистое количество минут без часов
    }
};
class Communication
{
public:
    //В массивах, хранящих время, первый элемент хранит часы, второй - минуты, третий - секунды
    int timeVideo[3] = {}, newTimeForValue[3] = {}, newTimeForIdle[3] = {};
    //Первый элемент - просмотренная длительность видео, второй - пропущенная;
    int dividedSegments[2] = {};
    void times()
    {
        cout << "Введите длительность видео.\nЧасов:  ";
        cin >> timeVideo[0];
        cout << "Минут:  ";
        cin >> timeVideo[1];
        cout << "Секунд: ";
        cin >> timeVideo[2];
    }
    void Finish()
    {
        cout << "\nПросмотренное время составляет " << newTimeForValue[0] << ":" << newTimeForValue[1] << ":" << newTimeForValue[2] << "\n";
        cout << "А непросмотренное " << newTimeForIdle[0] << ":" << newTimeForIdle[1] << ":" << newTimeForIdle[2] << "\n\n";
    }
};

int main()
{
    Duration Dur;
    Communication Info;
    Count Transfer;
    Info.times();
    Dur.newDuration(Transfer.countInSec(Info.timeVideo), Info.dividedSegments);
    Transfer.countOutSec(Info.dividedSegments[0], Info.newTimeForValue);
    Transfer.countOutSec(Info.dividedSegments[1], Info.newTimeForIdle);
    Info.Finish();
}