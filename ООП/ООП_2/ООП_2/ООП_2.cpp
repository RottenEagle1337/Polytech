#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

void First();
void Second();
void Third();
void Fourth();
void Fifth();
void Sixth();
void Seventh();
void Eighth();

int main()
{
    setlocale(LC_ALL, "rus");

    //First();
    //Second();
    //Third();
    //Fourth();
    //Fifth();

    return 0;
}

void First() {
    for (int i = 1; i <= 20*2; i+=2) {
        int n = (41 - i) / 2;

        cout << setw(n);

        for (int j = 1; j <= i; j++) {
            cout << "x";
        }

        cout << endl;
    }
}

void Second() {
    unsigned int numb;

    cout << "Enter a number: ";
    cin >> numb;

    while (numb != 0) {
        unsigned long fact = 1;

        for (int j = numb; j > 0; j--)      
            fact *= j;

        cout << "Factorial is " << fact << endl;

        cout << "Enter a number: ";
        cin >> numb;
    }
}

void Third() {
    float a, b, c;

    cout << "Введите начальный вклад: ";
    cin >> a;
    cout << "Введите число лет: ";
    cin >> b;
    cout << "Введите процентную ставку: ";
    cin >> c;

    for (int i = 0; i < b; i++) {
        a += a * (c / 100);
    }

    cout << "Через " << b << " лет вы получите " << a << " доллара." << endl;
}

void Fourth() {
    

    while (true)
    {
        int a1, a2, a3, b1, b2, b3;
        char s;

        cout << "Введите первую сумму: ";
        cin >> a1 >> a2 >> a3;
        cout << "Введите вторую сумму: ";
        cin >> b1 >> b2 >> b3;

        a3 += b3;
        if (a3 >= 12) {
            a2++;
            a3 -= 12;
        }

        a2 += b2;
        if (a2 >= 20) {
            a1++;
            a2 -= 20;
        }

        a1 += b1;

        cout << "Всего: " << a1 << " " << a2 << " " << a3 << endl;

        cout << "Continue?(y/n)" << endl;
        cin >> s;

        if (s == 'n')
            break;
    }
}

void Fifth() {
    int a, b;
    int result = 1;

    cout << "Введите кол-во гостей и мест: ";
    cin >> a >> b;

    for (int i = b; b > 0; b--) {
        result *= a;
        a--;
    }

    cout << "Всего возможно " << result << " рассадок" << endl;
}