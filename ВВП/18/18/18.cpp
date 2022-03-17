#include <clocale>
#include <iostream>
#include <vector> //подключение библиотеки с типом данных вектор, с ними удобнее работать


using namespace std;

// список реализованных функций
// принимаю везде указатели, тк меняю значения в функциях, да и памяти меньше занимает
void Swap(vector<float> *A, vector<float> *B); 
vector<float> doAvg(vector<float> *A);
void plusEven(vector<int> *A);
void setZero(vector<float> *A);
void sortFirst(vector<float> *A);


int main()
{
    setlocale(LC_ALL, "Russian"); // добавление русского языка в консоль
    int n;
    int num; // тут должен быть float, но я проверял 3ю функцию, где нужны целые числа
    cout << "введите n: ";
    cin >> n;

    // создание векторов размера n
    vector<float> A;
    vector<int> B;
    vector<float> C;
    A.resize(n);
    B.resize(n);
    C.resize(n);

    // заполнение векторов, с типами данных для проверки я начудил, но в функциях всё как в задании
    for (int i = 0; i < n*2; i++) { 
        if (i - n < 0) {
            cout << "введите очередное число массива A: ";
            cin >> num;
            A[i] = num;
        }
        else {
            cout << "введите очередное число массива B: ";
            cin >> num;
            B[i-n] = num;
        }
    }

    // проверки, можно подставить
    //Swap(&A, &B);
    //sortFirst(&A);
    setZero(&A);
    for (float e : A)
        cout << e << "\t";
    cout << endl;

    //plusEven(&B);
    for (int e : B)
        cout << e << "\t";

    cout << endl;
    //C = doAvg(&A);
    for (float e : C)
        cout << e << "\t";


    
	return 0;
    
}

// сами функции по порядку
void Swap(vector<float> *A, vector<float> *B) {
    float n = (*A).at(0);

    for (int i = 0; i < (*A).size(); i++) {
        n = (*A).at(i);
        (*A).at(i) = (*B).at(i);
        (*B).at(i) = n;
    }
}

vector<float> doAvg(vector<float> *A) {
    float sum = 0;
    vector<float> B;

    B.resize((*A).size());

    for (int i = 0; i < (*A).size(); i++) {
        sum += (*A).at(i);
        B.at(i) = sum / (i + 1);
    }

    return B;
}

void plusEven(vector<int> *A) {
    reverse((*A).begin(), (*A).end());
    int d = 0;
    bool f = false;
    for (int i = 0; i < (*A).size(); i++) {
        if (!f and (*A).at(i) % 2 == 0) {
            d = (*A).at(i);
            f = true;
            (*A).at(i) += d;
            cout << 1 << endl;
        }
        else if ((*A).at(i) % 2 == 0)
            (*A).at(i) += d;
    }
    reverse((*A).begin(), (*A).end());
}

void setZero(vector<float> *A) {
    float ma = (*A).at(0), mi = (*A).at(0);
    bool f = false;
    for (float e : *A) {
        if (e > ma)
            ma = e;
        if (e < mi)
            mi = e;
    }
    for (int i = 0; i < (*A).size(); i++) {
        if (((*A).at(i) == mi or (*A).at(i) == ma) and !f)
            f = true;
        else if (((*A).at(i) == mi or (*A).at(i) == ma) and f)
            break;
        else if (f) {
            (*A).at(i) = 0;
        }
    }
}

void sortFirst(vector<float> *A) {
    float n = (*A).at(0);
    (*A).erase((*A).begin());
    for (int i = 1; i < (*A).size(); i++) {
        if (n > (*A).at(i - 1) and n < (*A).at(i))
            (*A).emplace((*A).begin() + i, n);
    }
}