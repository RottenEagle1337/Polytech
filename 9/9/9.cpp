﻿#include <clocale>
#include <iostream>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");


    int n;
    cout << "Введите целое значение секунд: ";
    cin >> n;
    cout << "С последней минуты прошло " << n % 60 << " секунд" << endl;


    int k;
    cout << "Введите номер дня недели: ";
    cin >> k;
    cout << "В этом году номер этого дня = " << k % 7 << endl;


    cout << "Введите номер дня недели: ";
    cin >> k;
    cout << "Введите номер 1 января в этом году: ";
    cin >> n;
    cout << "В этом году номер этого дня = " << k % 7 + n << endl;


    int a, b, c;
    cout << "Введите стороны прямоугольника: ";
    cin >> a >> b;
    cout << "Введите сторону квадрата: ";
    cin >> c;
    // разбил вывод на 3 строки, чтобы удобнее было смотреть код
    // использовал алгоритм из прошлой работы
    cout << "В этот прямоугольник можно впихнуть " << ((int) a / c) * ((int) b / c);
    cout << " таких квадратов и останется ещё " << a * b - c * c * ((int) a / c) * ((int) b / c);
    cout << " пустых ячеек" << endl;


    cout << "Введите номер года: ";
    cin >> n;
    if (n % 100 >= 1)
        cout << "Этот год относится к " << ((int) n / 100) + 1 << " веку" << endl;
    else
        cout << "Этот год относится к " << (int) n / 100 << " веку" << endl;


    return 0;
}