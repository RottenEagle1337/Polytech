#include <iostream>
#include <clocale>
#include <string>

using namespace std;

void First();

int main()
{
    setlocale(LC_ALL, "rus");

    First();

    return 0;
}

void First() {
    for (int i = 1; i <= 20; i++) {
        cout << string(i, 'x') << endl;
    }
}