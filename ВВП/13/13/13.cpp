#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    short n;
    cout << "Введите цену 1кг кофет: ";
    cin >> n;
    for (float i = 1; i <= 10; i++) {
        cout << i / 10 << "кг конфет стоит " << (i / 10) * n << endl;
    }


    cout << "Введите число n: ";
    cin >> n;
    float m = 0.1, s = 1;
    while ((int) (m * 10) <= n) { //без перевода float в int будут неточные значения
        
        s *= (m + 1);
        m += 0.1;   
    }
    cout << "Произведение " << n << " множителей = " << s << endl;


    cout << "Введите число n: ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= (2 * n - 1); i += 2) {
        sum += i;
        cout << sum << endl;
    }
    cout << "Квадрат числа " << n << " = " << sum << endl;


    s = 1;
    float a;
    cout << "Введите вещественное число A и целое число N: ";
    cin >> a >> n;
    for (int i = 1; i <= n; i++) {
        s += pow(a,i);
    }
    cout << "Сумма ряда = " << s << endl;


    s = 1, a = 0;
    cout << "Введите вещественное число A и целое число N: ";
    cin >> a >> n;
    a = -a;
    for (int i = 1; i <= n; i++) {
        s += pow(a, i);
    }
    cout << "Сумма ряда = " << s << endl;


    return 0;
}