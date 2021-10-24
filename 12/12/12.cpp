#include <clocale>
#include <iostream>
#include <string>


using namespace std;


void dayMonth(int a, int b); // первое задание, занимает много места, сделал в функции
void Robot(string s, int a);
void Task(int a);
void Number(int a);
void Year(int a);


int main()
{
    setlocale(LC_ALL, "Russian");


    int a, b;
    cout << "Введите число и месяц: ";
    cin >> a >> b;
    dayMonth(a, b);


    string s;
    cout << "Введите направление и команду: ";
    cin >> s >> a;
    Robot(s, a);


    cout << "Введите кол-во учебных заданий: ";
    cin >> a;
    Task(a);


    cout << "Введите число: ";
    cin >> a;
    Number(a);


    cout << "Введите год: ";
    cin >> a;
    Year(a);


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


void Robot(string s, int a) {
    int b;
    if (s == "N") {
        if (a == 0)
            cout << "N" << endl;
        else if (a == 1)
            cout << "W" << endl;
        else
            cout << "E" << endl;
    }
    else if (s == "E") {
        if (a == 0)
            cout << "E" << endl;
        else if (a == 1)
            cout << "N" << endl;
        else
            cout << "S" << endl;
    }
    else if (s == "S") {
        if (a == 0)
            cout << "S" << endl;
        else if (a == 1)
            cout << "E" << endl;
        else
            cout << "W" << endl;
    }
    else {
        if (a == 0)
            cout << "W" << endl;
        else if (a == 1)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
}

void Task(int a) {
    if (a/10 == 1) {
        switch (a) {
        case 10:
            cout << "Десять учебных заданий";
            break;
        case 11:
            cout << "Одиннадцать учебных заданий";
            break;
        case 12:
            cout << "Двенадцать учебных заданий";
            break;
        case 13:
            cout << "Тринадцать учебных заданий";
            break;
        case 14:
            cout << "Четырнадцать учебных заданий";
            break;
        case 15:
            cout << "Пятнадцать учебных заданий";
            break;
        case 16:
            cout << "Шестнадцать учебных заданий";
            break;
        case 17:
            cout << "Семнадцать учебных заданий";
            break;
        case 18:
            cout << "Восемнадцать учебных заданий";
            break;
        case 19:
            cout << "Девятнадцать учебных заданий";
            break;
        }
    }
    else {
        if (a / 10 == 2)
            cout << "Двадцать ";
        else if (a / 10 == 3)
            cout << "Тридцать ";
        else
            cout << "Сорок";

        switch (a % 10) {
        case 1:
            cout << "одно ";
            break;
        case 2:
            cout << "два ";
            break;
        case 3:
            cout << "три ";
            break;
        case 4:
            cout << "четыре ";
            break;
        case 5:
            cout << "пять ";
            break;
        case 6:
            cout << "шесть ";
            break;
        case 7:
            cout << "семь ";
            break;
        case 8:
            cout << "восемь ";
            break;
        case 9:
            cout << "девять ";
            break;
        }

        if (a % 10 == 1)
            cout << "учебное задание";
        else if (a % 10 >= 2 and a % 10 <= 4)
            cout << "учебных задания";
        else
            cout << "учебных заданий";
    }
    cout << endl;
}

void Number(int a) {
    switch (a / 100) {
    case 1:
        cout << "Сто ";
        break;
    case 2:
        cout << "Двести ";
        break;
    case 3:
        cout << "Триста ";
        break;
    case 4:
        cout << "Четыреста ";
        break;
    case 5:
        cout << "Пятьсот ";
        break;
    case 6:
        cout << "Шестьсот ";
        break;
    case 7:
        cout << "Семьсот ";
        break;
    case 8:
        cout << "Восемьсот  ";
        break;
    case 9:
        cout << "Девятьсот  ";
        break;
    }

    if ((a % 100) / 10 == 1)
        switch (a % 100) {
        case 10:
            cout << "десять";
            break;
        case 11:
            cout << "одинадцать";
            break;
        case 12:
            cout << "двенадцать";
            break;
        case 13:
            cout << "тринадцать";
            break;
        case 14:
            cout << "четырнадцать";
            break;
        case 15:
            cout << "пятнадцать";
            break;
        case 16:
            cout << "шестнадцать";
            break;
        case 17:
            cout << "семнадцать";
            break;
        case 18:
            cout << "восемнадцать";
            break;
        case 19:
            cout << "девятнадцать";
            break;
        }
    else {
        switch ((a % 100) / 10) {
        case 2:
            cout << "двадцать ";
            break;
        case 3:
            cout << "тридцать ";
            break;
        case 4:
            cout << "сорок ";
            break;
        case 5:
            cout << "пятьдесят ";
            break;
        case 6:
            cout << "шестьдесят ";
            break;
        case 7:
            cout << "семьдесят ";
            break;
        case 8:
            cout << "восемьдесят ";
            break;
        case 9:
            cout << "девяносто ";
            break;
        }

        switch (a % 10) {
        case 1:
            cout << "один";
            break;
        case 2:
            cout << "два";
            break;
        case 3:
            cout << "три";
            break;
        case 4:
            cout << "четыре";
            break;
        case 5:
            cout << "пять";
            break;
        case 6:
            cout << "шесть";
            break;
        case 7:
            cout << "семь";
            break;
        case 8:
            cout << "восемь";
            break;
        case 9:
            cout << "девять";
            break;
        }
    }
    cout << endl;
}

void Year(int a) {
    cout << "Год ";

    switch ((a) % 10) {
    case 0:
    case 1:
        cout << "бел";
        break;
    case 2:
    case 3:
        cout << "черн";
        break;
    case 4:
    case 5:
        cout << "зелён";
        break;
    case 6:
    case 7:
        cout << "красн";
        break;
    case 8:
    case 9:
        cout << "жёлт";
        break;
    }

    switch ((a + 1) % 5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 9:
    case 10:
    case 11:
        cout << "ой ";
        break;
    case 6:
    case 7:
    case 8:
        cout << "ого ";
        break;
    }

    switch ((a + 8) % 12) {
    case 0:
        cout << "крысы";
        break;
    case 1:
        cout << "коровы";
        break;
    case 2:
        cout << "тигра";
        break;
    case 3:
        cout << "зайца";
        break;
    case 4:
        cout << "дракона";
        break;
    case 5:
        cout << "змеи";
        break;
    case 6:
        cout << "лошади";
        break;
    case 7:
        cout << "овцы";
        break;
    case 8:
        cout << "обезьяны";
        break;
    case 9:
        cout << "курицы";
        break;
    case 10:
        cout << "собаки";
        break;
    case 11:
        cout << "свиньи";
        break;
    }
}