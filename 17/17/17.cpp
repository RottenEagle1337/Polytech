#include <vector>
#include <iostream>
#include <clocale>


using namespace std;


float Avg(vector<float> arr);
float Prog(vector<float> arr);
float minEven(vector<float> arr);


int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    float num;
    cout << "введите n: ";
    cin >> n;

    vector<float> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "введите очередное число массива: ";
        cin >> num;
        arr[i] = num;
    }


    cout << "ср арифметические среза массива = " << Avg(arr) << endl;
    cout << "шаг прогрессии = " << Prog(arr) << endl;
    cout << "мин четный эллемент = " << minEven(arr) << endl;
    return 0;
}

float Avg(vector<float> arr) {
    int k, l;
    cout << "введите k и l: ";
    cin >> k >> l;
    float sum = 0;
    for (int j = (k - 1); j < l; j++)
        sum += arr[j];
    return sum / (l - k + 1);
}

float Prog(vector<float> arr) {
    float d = (arr[1] - arr[0]);
    bool flag = false;
    for (int j = 1; j < (arr.size() - 1); j++) {
        if (arr[j + 1] - arr[j] != d) {
            flag = true;
            break;
        }
        d = arr[j + 1] - arr[j];
    }
    if (!flag)
        return d;
    else
        return 0;
}

float minEven(vector<float> arr) {
    int j = 2;
    float num = arr[0];
    while (j <= arr.size()) {
        if (arr[j] < num)
            num = arr[j];
        j += 2;
    }
    return num;
}