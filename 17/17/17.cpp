#include <vector>
#include <iostream>
#include <clocale>


using namespace std;


float Avg(vector<float>* arr);
float Prog(vector<float>* arr);
float minEven(vector<float>* arr);
float localMax(vector<float>* arr);
void Dublicate(vector<float>* arr);

void Recreate(vector<float>* arr); //вынес создание и заполнение массива в функцию


int main()
{
    setlocale(LC_ALL, "Russian");


    vector<float> arr;


    Recreate(&arr);
    cout << "ср арифметические среза массива = " << Avg(&arr) << endl;


    Recreate(&arr);
    cout << "шаг прогрессии = " << Prog(&arr) << endl;


    Recreate(&arr);
    cout << "мин четный эллемент = " << minEven(&arr) << endl;


    Recreate(&arr);
    cout << "номер последнего элемента локальный максимума = " << localMax(&arr) << endl;


    Recreate(&arr);
    Dublicate(&arr);


    return 0;
}

void Recreate(vector<float>* arr) {
    int n;
    cout << "введите размер массива: ";
    cin >> n;
    float num;
    (*arr).clear();
    (*arr).resize(n);
    for (int i = 0; i < n; i++) {
        cout << "введите очередное число массива: ";
        cin >> num;
        (*arr).at(i) = num;
    }
}


float Avg(vector<float>* arr) {
    int k, l;
    cout << "введите k и l: ";
    cin >> k >> l;
    float sum = 0;
    for (int j = (k - 1); j < l; j++) {
        sum += (*arr).at(j);
    }
    return (sum / (l - k + 1));
}

float Prog(vector<float>* arr) {
    float d = ((*arr).at(1) - (*arr).at(0));
    bool flag = false;
    for (int j = 1; j < ((*arr).size() - 2); j++) {
        if ((*arr).at(j + 1) - (*arr).at(j) != d) {
            flag = true;
            break;
        }
        d = (*arr).at(j + 1) - (*arr).at(j);
    }
    if (!flag)
        return d;
    else
        return 0;
}

float minEven(vector<float>* arr) {
    int j = 1;
    float num = (*arr).at(j);
    while (j < (*arr).size()) {
        if ((*arr).at(j) < num)
            num = (*arr).at(j);
        j += 2;
    }
    return num;
}

float localMax(vector<float>* arr) {
    bool f = true;
    float locMax = 0;
    for (int j = (*arr).size() - 2; j > 1; j--) {
        if (f and ((*arr).at(j + 1) > (*arr).at(j))) {
            locMax = j + 1;
            break;
        }
        if (((*arr).at(j - 1) <= (*arr).at(j)) and ((*arr).at(j + 1) <= (*arr).at(j))) {
            locMax = j;
            break;
        }
    }
    return locMax;
}

void Dublicate(vector<float>* arr) {
    bool f = false;
    for (int i = 1; i < ((*arr).size() - 2); i++) {
        for (int j = i + 1; j < ((*arr).size() - 1); j++) {
            if ((*arr).at(i) == (*arr).at(j)) {
                cout << i << " " << j << endl;
                break;
            }
        }
        if (f)
            break;
    }
}