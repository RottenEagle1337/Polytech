#include <clocale>
#include <iostream>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");


    int a;
    cout << "Введите размер файла в байтах: ";
    cin >> a;
    if (a % 1024 > 0)
        cout << "Кол-во полных килобайт файла = " << ((int)a / 1024) + 1 << endl;
    else
        cout << "Кол-во полных килобайт файла = " << (int)a / 1024 << endl;


    int b;
    cout << "Введите числа a и b( a > b ): ";
    cin >> a >> b;
    cout << "a вмещает в себя b " << (int) a / b << " раз" << endl;


    cout << "Введите числа a и b( a > b ): ";
    cin >> a >> b;
    cout << "Длина не занятой части а = " << a - b * ((int) a / b) << endl;


    int n;
    cout << "Введите число n( двузначное ): ";
    cin >> n;
    // a = n % 10;
    // b = (int) n / 10;
    // можно сделать через доп. переменные, но мне лень
    cout << "Число n наоборот = " << n % 10 << (int)n / 10 << endl;


    // принцип как в задании 4
    cout << "Введите число n( трёхзначное ): ";
    cin >> n;
    cout << "Число n с первой цифрой в конце = " << ((int)n / 10) % 10 << n % 10 << (int) n / 100 << endl;


    return 0;
}