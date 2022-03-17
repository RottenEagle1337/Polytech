#include <iostream>
#include <clocale>
#include <cmath> // для функции abs( модуль )


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");


    float a;
    cout << "Введите а( в градусах ): ";
    cin >> a;
    cout << "а( в радианах ) = " << (a / 360) * 2 * 3.14 << endl;


    cout << "Введите а( в радианах ): ";
    cin >> a;
    cout << "а( в градусах ) = " << (360 * a) / (2 * 3.14) << endl;


    float x, y;
    cout << "Введите кол-во конфет( в кг ) и их стоимость: ";
    cin >> x >> a;
    cout << "Введите желаемое кол-во конфет( в кг ): ";
    cin >> y;
    cout << "1кг таких конфет стоит " << a / x << endl;
    cout << y << "кг таких конфет стоит " << (a / x) * y << endl;


    float v1, v2, t;
    cout << "Введите скорость 1 и 2 автомобилей: ";
    cin >> v1 >> v2;
    cout << "Введите время поездки: ";
    cin >> t;
    cout << "Через " << t << " ч. расстояние между ними будет = " << abs(t * (v1 - v2)) << endl;


    float b;
    cout << "Введите коэффициенты a и b для уравнения вида a*x + b = 0: ";
    cin >> a >> b;
    cout << "x = " << -b / a << endl;


    float c, a1, b1, c1;
    cout << "Введите коэффициенты a и b для первого уравнения вида a*x + b*y = c: ";
    cin >> a >> b >> c;
    cout << "Введите коэффициенты a и b для второго уравнения вида a1*x + b1*y = c1: ";
    cin >> a1 >> b1 >> c1;
    // для упрощения вычислений ввёл дополнительную переменную
    x = (c1 * b - c * b1) / (a1 * b - a * b1);
    cout << "x = " << x << endl;
    cout << "y = " << (c - a * x) / b << endl;


    return 0;
}