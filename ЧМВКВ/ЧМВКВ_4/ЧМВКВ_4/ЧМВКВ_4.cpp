#include <iostream>
#include <clocale>
#include <cmath>
#include <chrono>

using namespace std;

void NewtonMethod(double _x, double _y, double e);
void SimpleIterations(double _x, double _y, double e);

int main()
{
    setlocale(LC_ALL, "rus");

	double e, x, y;
	cout << "Введите приближённые значения x и y: ";
	cin >> x >> y;

	cout << "Введите погрешность: ";
	cin >> e;

	NewtonMethod(x, y, e);

	SimpleIterations(x, y, e);

    return 0;
}

void NewtonMethod(double _x, double _y, double e) {
	double x = _x, y = _y, x1, y1, det, F1, F2, m[2][2];
	int i = 0;
	do
	{
		x1 = x; 
		y1 = y;

		// матрица Якоби
		m[0][0] = -1;
		m[0][1] = sin(x1 - 2);
		m[1][0] = cos(y1 + 0.5);
		m[1][1] = 1;     	

		// определитель мматрицы
		det = m[0][0] * m[1][1] - m[0][1] * m[1][0];

		// обратная матрица
		m[0][0] /= det;
		m[1][1] /= det;
		m[0][1] /= (-det);
		m[1][0] /= (-det);

		F1 = sin(y1 + 0.5) - x1 - 1;
		F2 = cos(x1 - 2) + y1;

		// вычисление очередного значения
		x -= m[1][1] * F1 + m[0][1] * F2; 
		y -= m[1][0] * F1 + m[0][0] * F2;

		i++;

	} while ((abs(x - x1) > e) || (abs(y - y1) > e));
	cout << "\nx = " << x << "\ny = " << y << "\nКоличество итераций: " << i << endl;
}

void SimpleIterations(double _x, double _y, double e)
{
	double x = _x, y = _y, x1, y1;
	int i = 0;
	do
	{
		x1 = x;
		y1 = y;
		x = sin(y + 0.5) - 1;
		y = -cos(x - 2);
		i++;
	} while ((abs(x - x1) > e) || (abs(y - y1) > e));
	cout << "\nx = " << x << "\ny = " << y << "\nКоличество итераций: " << i << endl;
}