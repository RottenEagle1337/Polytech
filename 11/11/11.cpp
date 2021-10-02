#include <clocale>
#include <iostream>
#include <cmath>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");


    int a, b;
    cout << "Введите a и b: ";
    cin >> a >> b;
    if (a == b)
        a = 0, b = 0;
    else {
        a = max(a, b), b = a;
    }
    cout << "Новое значение а = " << a << "; новое значение b = " << b << endl;


    int c;
    cout << "Введите 3 числа: ";
    cin >> a >> b >> c;
    cout << "Сумма 2 наибольших чисел = " << a + b + c - min(min(a, b), min(b, c)) << endl;


    cout << "Введите 3 точки на числовой прямой: ";
    cin >> a >> b >> c;
    if (abs(a - b) <= abs(a - c))
        cout << "Точка b расположена ближе к a, расстояние между ними = " << abs(a - b) << endl;
    else
        cout << "Точка c расположена ближе к a, расстояние между ними = " << abs(a - c) << endl;


    float x, y;
    cout << "Введите координаты точки( не лежат на осях ): ";
    cin >> x >> y;
    if (x > 0 and y > 0)
        cout << "Точка принадлежит I координатной четверти" << endl;
    else if (x < 0 and y > 0)
        cout << "Точка принадлежит II координатной четверти" << endl;
    else if (x < 0 and y < 0)
        cout << "Точка принадлежит III координатной четверти" << endl;
    else
        cout << "Точка принадлежит IV координатной четверти" << endl;


    cout << "Введите число: ";
    cin >> a;
    if (a == 0) {
        cout << "Нулевое число" << endl;
        goto Next; // перемещает нас сразу к Next:, потому что остальные проверки уже не нужны
    }
    else if (a > 0)
        cout << "Положительное ";
    else
        cout << "Отрицательное ";
    if (a % 2 == 0)
        cout << "чётное число" << endl;
    else
        cout << "нечётное число" << endl;
    Next:

    cout << "Введите число в диапазоне от 1 до 999: ";
    cin >> a;
    if (a % 2 == 0)
        cout << "Чётное ";
    else
        cout << "Нечётное ";
    if (a - 99 >= 1)
        cout << "трёхзначное число" << endl;
    else
        cout << "двухзначное число" << endl;


    return 0;
}