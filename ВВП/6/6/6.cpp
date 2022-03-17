#include <iostream>
#include <clocale>
#include <cmath>


using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");


	float a, b, n;
	cout << "Введите переменные a и b: ";
	cin >> a >> b;
	n = a;
	a = b;
	b = n;
	cout << "Теперь a = " << a << " ,а b = " << b << endl;


	float c; // добовляю ещё одну переменную
	cout << "Введите переменные a, b и c: ";
	cin >> a >> b >> c;
	n = b;
	b = a;
	a = c;
	c = n;
	cout << "Теперь a = " << a << " , b = " << b << " ,а c = " << c << endl;
	

	// перезаписываю переменные
	cout << "Введите переменные a, b и c: ";
	cin >> a >> b >> c;
	n = a;
	a = b;
	b = c;
	c = n;
	cout << "Теперь a = " << a << " , b = " << b <<" ,а c = " << c << endl;


	float x; // создаю новую переменную для удобства
	cout << "Введите х: ";
	cin >> x;
	cout << "Значение выражения 3x^6 - 6x^2 - 7 = " << 3 * pow(x, 6) - 6 * pow(x, 2) - 7 << endl;

	
	// перезаписываю старую переменную
	cout << "Введите х: ";
	cin >> x;
	cout << "Значение выражения 4(x - 3)^6 - 7(x - 3)^3 + 2 = " << 4 * pow(x - 3, 6) - 7 * pow(x - 3, 3) + 2 << endl;


    // использую старые переменные
	cout << "Введите A: ";
	cin >> a;
	n = a * a;
	cout << "A^8 = " << n * n * n << endl;


	// использую старые переменные и создаю 1 новую для удобства
	float n1;
	cout << "Введите A: ";
	cin >> a;
	n = a * a;
	n1 = n * a;
	cout << "A^15 = " << n1 * n1 * n1 * n1 *n1 << endl;


	return 0;
}