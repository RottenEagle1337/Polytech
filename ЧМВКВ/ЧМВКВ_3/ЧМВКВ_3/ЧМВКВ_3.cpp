#include <iostream>
#include <clocale>
#include <cmath>
#include <chrono>

using namespace std;

void NewtonMethod(float a, float b, double e);
void ChordMethod(float a, float b, double e);

int main()
{
    setlocale(LC_ALL, "rus");

    float a, b;
    double e;

    cout << "Введите концы отрезка: ";
    cin >> a >> b;
    cout << "Введите погрешность: ";
    cin >> e;

    auto start = chrono::high_resolution_clock::now();

    NewtonMethod(a, b, e);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << ", время выполнения = " << duration.count() << " сек" << endl;


    cout << endl;


    start = chrono::high_resolution_clock::now();

    ChordMethod(a, b, e);

    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << ", время выполнения = " << duration.count() << " сек" << endl;

    return 0;
}

void NewtonMethod(float a, float b, double e) {
    float c0, c1, buff;
    int i = 0;

    if (((sin(0.5 + a) - 2 * a + 0.5) * -(sin(0.5 + a))) > 0) {
        c0 = a;
    }
    else
        c0 = b;
    
    c1 = c0;

    do {
        buff = c1;
        c1 = c0 - (sin(0.5 + c0) - 2 * c0 + 0.5) / (cos(0.5 + c0) - 2);
        c0 = c1;

        i++;
    } while (abs(c1 - buff) >= e);

    cout << "Значение корня x = " << c1 << ", кол-во итераций = " << i;
}

void ChordMethod(float a, float b, double e) {
    float c1 = max(a,b), buff;
    int i = 0;

    do {
        buff = c1;
        c1 = a - (b - a) * (sin(0.5 + a) - 2 * a + 0.5) / ((sin(0.5 + b) - 2 * b + 0.5) - (sin(0.5 + a) - 2 * a + 0.5));

        if ((sin(0.5 + a) - 2 * a + 0.5) * (sin(0.5 + c1) - 2 * c1 + 0.5) < 0) {
            b = c1;
        }
        else
            a = c1;

        i++;
    } while (abs(c1 - buff) >= e);

    cout << "Значение корня x = " << c1 << ", кол-во итераций = " << i;
}