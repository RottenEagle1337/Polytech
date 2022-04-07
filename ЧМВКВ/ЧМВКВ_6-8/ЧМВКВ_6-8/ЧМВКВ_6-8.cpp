#include<iostream>
#include <clocale>
#include <iomanip>
#include<cmath>

using namespace std;

double Func(double x);
double Integralpram(double a, double b, int n);
double trapezoidalIntegral(double a, double b, int n);
double simpsonIntegral(double a, double b, int n);

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите кол-во отрезков: ";
    cin >> n;

    cout << "Значение интеграла по калькулятору = " << setprecision(10) << 198 - pow(log(5), 2) + 100 * pow(log(500), 2) + log(25) - 200 * log(500) << endl;

    cout <<"Методом прямоугольников = " << setprecision(10) << Integralpram(1.0000, 100.0000, n) << endl;

    cout << "Методом трапеций = " << setprecision(10) << trapezoidalIntegral(1.0000, 100.0000, n) << endl;

    cout << "Методом Симпсона = " << setprecision(10) << simpsonIntegral(1.0000, 100.0000, n) << endl;

    return 0;
}

double Func(double x)
{
    return (double)pow(log(5 * x), 2);
}

double Integralpram(double a, double b, int n)
{
    double h, S, x;
    int i;
    h = (b - a) / n;
    S = 0;

    for (i = 0; i < n - 1; i++)
    {
        x = a + i * h;
        S = S + Func(x);
    }

    S = h * S;
    return S;
}

double trapezoidalIntegral(double a, double b, int n) {
    double h, x1, x2;
    h = (b - a) / n;

    double S = 0;
    for (int i = 0; i < n; i++) {
        x1 = a + i * h;
        x2 = a + (i + 1) * h;

        S += 0.5 * (x2 - x1) * (Func(x1) + Func(x2));
    }

    return S;
}

double simpsonIntegral(double a, double b, int n) {
    double h, x1, x2, S = 0;
    h = (b - a) / n;

    for (int step = 0; step < n; step++) {
        x1 = a + step * h;
        x2 = a + (step + 1) * h;

        S += (x2 - x1) / 6.0 * (Func(x1) + 4.0 * Func(0.5 * (x1 + x2)) + Func(x2));
    }

    return S;
}