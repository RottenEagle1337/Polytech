#include <clocale>
#include <iostream>
#include <cstring>


using namespace std;


void dayMonth(int a, int b); // первое задание, занимает много места, сделал в функции
void Robot(char s, int a);


int main()
{
    setlocale(LC_ALL, "Russian");


    int a, b;
    cout << "Введите число и месяц: ";
    cin >> a >> b;
    dayMonth(a, b);


    char s;
    cout << "Введите направление и команду: ";
    cin >> s >> a;
    Robot(s, a);



    return 0;
}


void dayMonth(int a, int b) {
Again:
    if (a <= 20 or (a == 30 or a == 31)) {
        switch (a)
        {
        case 1:
            cout << "первое ";
            break;
        case 2:
            cout << "второе ";
            break;
        case 3:
            cout << "третье ";
            break;
        case 4:
            cout << "четвёртое ";
            break;
        case 5:
            cout << "пятое ";
            break;
        case 6:
            cout << "шестое ";
            break;
        case 7:
            cout << "седьмое ";
            break;
        case 8:
            cout << "восьмое ";
            break;
        case 9:
            cout << "девятое ";
            break;
        case 10:
            cout << "десятое ";
            break;
        case 11:
            cout << "одиннадцатое ";
            break;
        case 12:
            cout << "двенадцатое ";
            break;
        case 13:
            cout << "тринадцатое ";
            break;
        case 14:
            cout << "четырнадцатое ";
            break;
        case 15:
            cout << "пятнадцатое ";
            break;
        case 16:
            cout << "шестнадцатое ";
            break;
        case 17:
            cout << "семнадцатое ";
            break;
        case 18:
            cout << "восемнадцатое ";
            break;
        case 19:
            cout << "девятнадцатое ";
            break;
        case 20:
            cout << "двадцатое ";
            break;
        case 30:
            cout << "тридцатое ";
            break;
        case 31:
            cout << "тридцать первое ";
            break;
        default:
            break;
        }
    }
    else if (a < 30 and a > 20) {
        cout << "двадцать ";
        a %= 10;
        goto Again;
    }
    switch (b)
    {
    case 1:
        cout << "января" << endl;
        break;
    case 2:
        cout << "февраля" << endl;
        break;
    case 3:
        cout << "марта" << endl;
        break;
    case 4:
        cout << "апреля" << endl;
        break;
    case 5:
        cout << "мая" << endl;
        break;
    case 6:
        cout << "июня" << endl;
        break;
    case 7:
        cout << "июля" << endl;
        break;
    case 8:
        cout << "августа" << endl;
        break;
    case 9:
        cout << "сентября" << endl;
        break;
    case 10:
        cout << "октября" << endl;
        break;
    case 11:
        cout << "ноября" << endl;
        break;
    case 12:
        cout << "декабря" << endl;
        break;
    }
}


void Robot(char s, int a) {
    int b = 0;
    if (strcmp(&s, "С") == 0) {
        b = 0;
        cout << "0" << endl;
    }
    else if (strcmp(&s, "В") == 0) {
        b = 1;
        cout << "1" << endl;
    }
    else if (strcmp(&s, "Ю") == 0) {
        b = 2;
        cout << "2" << endl;
    }
    else {
        b = 3;
        cout << "3" << endl;
    }
    switch (a)
    {
    case 0:
        break;
    case 1:
        if (b + 1 > 3)
            b -= 3;
        else
            b++;
        break;
    case -1:
        if (b - 1 < 0)
            b += 3;
        else
            b--;
        break;
    }
    switch (b)
    {
    case 0:
        cout << "С" << endl;
        break;
    case 1:
        cout << "В" << endl;
    case 2:
        cout << "Ю" << endl;
    case 3:
        cout << "З" << endl;
    }
}