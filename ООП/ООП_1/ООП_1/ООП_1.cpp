#include <iostream>
#include <clocale>
#include <ctype.h>
#include <iomanip>

using namespace std;

void First();
void Second();
void Third();
void Fourth();
void Fifth();
void Sixth();
void Seventh();
void Eighth();
void Ninth();

int main()
{
    setlocale(LC_ALL, "Rus");
    
    First();
    Second();
    Third();
    Fourth();
    Fifth();
    Sixth();
    Seventh();
    Eighth();
    Ninth();

    return 0;
}

void First() {
    cout << "Белая берёза\nПод моим окном\nПринакрылась снегом,\nТочно серебром.\n\nНа пушистых ветках\nСнежною каймой\nРаспустились кисти\nБелой бахромой.\n\nИ стоит берёза\nВ сонной тишине,\nИ горят снежинки\nВ золотом огне.\n\nА заря, лениво\nОбходя кругом\nОбсыпает ветки\nНовым серебром.\n" << endl;
}

void Second() {
    char a;
    cout << "Введите букву: ";
    cin >> a;
    cout << islower(a) << "\n" << endl;
}

void Third() {
    int a;
    cout << "Введите значение($): ";
    cin >> a;
    cout << "Фунт = " << a / 1.478f << " Франк = " << a / 0.172f << " Марка = " << a / 0.584f << " Йена = " << a / 0.00955f << "\n" << endl;
}

void Fourth() {
    float a;
    cout << "Введите температуру(C): ";
    cin >> a;
    cout << a * 9 / 5 + 32 << " Ф\n" << endl;
}

void Fifth() {
    cout << setfill('.') << 1990 << setw(8) << 135 << endl << 1991 << setw(8) << 7290 << endl << 1992 << setw(8) << 11300 << endl << 1993 << setw(8) << 16200 << "\n" << endl;
}

void Sixth() {
    char s;
    int a, b, c, d;
    cout << "Введите первую дробь: ";
    cin >> a >> s >> b;
    cout << "Введите вторую дробь: ";
    cin >> c >> s >> d;
    cout << "Сумма = " << (a * d + b * c) << "/" << (b * d) << "\n" << endl;
}

void Seventh() {
    int a, b, c;
    cout << "Введите кол-во фунтов: ";
    cin >> a;
    cout << "Введите кол-во шиллингов: ";
    cin >> b;
    cout << "Введите кол-во пенсов: ";
    cin >> c;
    cout << "Десятичных фунтов: £" << a << "." << (b * 12 + c) * 100 / 240 << "\n" << endl;
}

void Eighth() {
    cout << setfill(' ') << setiosflags(ios::left) << setw(20) << "Фамилия" << setw(20) << "Имя" << setw(20) << "Адрес" << setw(15) << "Город" << endl;
    cout << setiosflags(ios::left) << setw(20) << "Петров" << setw(20) << "Василий" << setw(20) << "Кленовая 20" << setw(15) << "Санкт-Петербург" << endl;
    cout << setiosflags(ios::left) << setw(20) << "Иванов" << setw(20) << "Сергей" << setw(20) << "Осиновая 3" << setw(15) << "Находка" << endl;
    cout << setiosflags(ios::left) << setw(20) << "Сидоров" << setw(20) << "Иван" << setw(20) << "Березовая 21" << setw(15) << "Калининград\n" << endl;
}

void Ninth() {
    int a, b, c;
    char s;
    cout << "Введите число десятичных фунтов: ";
    cin >> a >> s >> b;
    cout << "Эквивалентная сумма в старой форме записи: £" << a << "." << (int)(b * 240 / 100) / 12 << "." << (b * 240 / 100) - ((int)(b * 240 / 100) / 12) * 12 << "\n" << endl;
}