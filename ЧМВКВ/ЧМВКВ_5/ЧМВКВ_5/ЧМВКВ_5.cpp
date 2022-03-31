#include <iostream>
#include <clocale>

using namespace std;

void Method();

int main()
{
    setlocale(LC_ALL, "rus");

    Method();

    return 0;
}

void Method() {
    double a = 1, b = 2, c = 1, d = 60;
    const int n = 100;
    double U[n], V[n], X[n];

    U[0] = double(-c / b);
    V[0] = double(d / b);

    cout << "U1 = " << U[0] << " V1 = " << V[0] << endl;
    for (int i = 1; i <= n - 1; i++)
    {
        U[i] = (-1 * c) / (a * U[i - 1] + b);
        V[i] = (d - (a * V[i - 1])) / ((a * U[i - 1]) + b);
    }

    X[n - 1] = (d - (a * V[n - 2])) / ((a * U[n - 2]) + b);
    cout << "X[" << n << "] = " << X[n - 1] << endl;

    for (int i = n - 2; i >= 1; i--)
    {
        X[i] = (-c * X[i + 1]) / ((a * U[i - 1]) + b) + ((d - a * V[i - 1]) / (a * U[i - 1] + b));
        cout << "X[" << i + 1 << "]= " << X[i] << endl;
    }

    cout << "X[1]= " << U[0] * X[1] + V[0] << endl;
}