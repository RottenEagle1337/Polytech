#include <iostream>
#include <clocale>

using namespace std;

void First();
void Second();

struct employee
{
    int id;
    float money;
};

struct date {
    int day, month, year;
};

int main()
{
    setlocale(LC_ALL, "rus");

    //First();
    //Second();

    return 0;
}

void First() {
    employee n1, n2, n3;
    cout << "Введите данные о сотруднике №1(ID и пособие):";
    cin >> n1.id >> n1.money;

    cout << "Введите данные о сотруднике №2(ID и пособие):";
    cin >> n2.id >> n2.money;

    cout << "Введите данные о сотруднике №3(ID и пособие):";
    cin >> n3.id >> n3.money;

    cout << "\nСотрудник c ID: " << n1.id << " имеет пособие: " << n1.money << endl;
    cout << "Сотрудник c ID: " << n2.id << " имеет пособие: " << n2.money << endl;
    cout << "Сотрудник c ID: " << n3.id << " имеет пособие: " << n3.money << endl;
}

void Second() {
    date _date;
    char op[2];
    cout << "Введите дату(в формате ХХ/ХХ/ХХХХ): ";
    cin >> _date.day >> op[0] >> _date.month >> op[1] >> _date.year;
    cout << "Вы ввели: " << _date.day << " " << _date.month << " " << _date.year;
}
