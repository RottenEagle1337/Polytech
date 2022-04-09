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
    Third();
    //Fourth();
    //Fifth();
    //Sixth();
    //Eighth();
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

void Sixth() {
    float a, b, c;
    int i = 0;

    cout << "Введите начальный вклад: ";
    cin >> a;
    cout << "Введите процентную ставку: ";
    cin >> b;
    cout << "Введите желаемый результат: ";
    cin >> c;

    while (a < c) {
        a += a * (b / 100);
        i++;
    }

    cout << "Через " << i << " лет вы достигните цели" << endl;
}

void Seventh() {
    int a1, a2, a3, b1, b2, b3, n;

    char oper;

    cout << "Введите первую сумму: ";
    cin >> a1 >> a2 >> a3;

    cout << "Введите знак: ";
    cin >> oper;

    switch (oper)
    {
    case '+':
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

        cout << "Сумма: " << a1 << " " << a2 << " " << a3 << endl;

        break;

    case '-':
        cout << "Введите вторую сумму: ";
        cin >> b1 >> b2 >> b3;

        a3 -= b3;
        if (a3 < 0) {
            a2--;
            a3 += 12;
        }

        a2 -= b2;
        if (a2 < 0) {
            a1--;
            a2 += 20;
        }

        a1 -= b1;

        cout << "Разность: " << a1 << " " << a2 << " " << a3 << endl;

        break;

    case '*':
        cout << "Введите число: ";
        cin >> n;

        a3 *= n;
        a2 *= n;
        a1 *= n;

        if (a3 >= 12) {
            a2 += a3 / 12;
            a3 %= 12;
        }

        if (a2 >= 20) {
            a1 += a2 / 20;
            a2 %= 20;
        }

        cout << "Ответ: " << a1 << " " << a2 << " " << a3 << endl;

        break;

    default:
        cout << "Ошибка знака!" << endl;
    }
}

void Eighth() {
    int a, b, c, d;
    char op, n;

    cout << "Введите первую дробь: ";
    cin >> a >> n >> b;
    cout << "Введите знак: ";
    cin >> op;
    cout << "Введите вторую дробь: ";
    cin >> c >> n >> d;

    switch (op)
    {
    case '+':
        cout << "Сумма = " << (a * d + b * c) << "/" << (b * d) << endl;
        break;
    case '-':
        cout << "Разность = " << (a * d - b * c) << "/" << (b * d) << endl;
        break;
    case '*':
        cout << "Произведение = " << (a * c) << "/" << (b * d) << endl;
        break;
    case '/':
        cout << "Частное = " << (a * d) << "/" << (b * c) << endl;
        break;
    default:
        cout << "Ошибка!" << endl;
        break;
    }
}