#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int N = 10;

void fillDistinct(int a[], int n) {
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = n - 1; i > 0; i--) swap(a[i], a[rand() % (i + 1)]);
}

void fillRandom(int a[], int n, int lo, int hi) {
    for (int i = 0; i < n; i++) a[i] = rand() % (hi - lo + 1) + lo;
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// Завдання 3
void task3() {
    cout << "\nЗавдання 3" << endl;
    int a[N];
    fillDistinct(a, N);

    cout << "Масив: ";
    printArray(a, N);

    int iMax = 0, iMin = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] > a[iMax]) iMax = i;
        if (a[i] < a[iMin]) iMin = i;
    }
    swap(a[iMax], a[iMin]);

    cout << "Після обміну: ";
    printArray(a, N);
}

// Завдання 4
void task4() {
    cout << "\nЗавдання 4" << endl;
    int a[N];
    fillRandom(a, N, -10, 10);

    cout << "Масив: ";
    printArray(a, N);

    int A, count = 0;
    cout << "Введіть A: ";
    cin >> A;

    for (int i = 0; i < N; i++)
        if (a[i] > A) count++;

    cout << "Елементів, більших за " << A << ": " << count << endl;
}

// Завдання 5
void task5() {
    cout << "\nЗавдання 5" << endl;
    int a[N];
    fillDistinct(a, N);

    cout << "Масив: ";
    printArray(a, N);

    int first, second;
    if (a[0] > a[1]) { first = a[0]; second = a[1]; }
    else { first = a[1]; second = a[0]; }

    for (int i = 2; i < N; i++) {
        if (a[i] > first) { second = first; first = a[i]; }
        else if (a[i] > second) { second = a[i]; }
    }

    cout << "Другий за величиною елемент: " << second << endl;
}

// Завдання 6
void task6() {
    cout << "\nЗавдання 6" << endl;
    int a[N];
    fillRandom(a, N, 0, 3);   

    cout << "Масив: ";
    printArray(a, N);

    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (a[i] == 0) { pos = i; break; }
    }

    if (pos == -1)
        cout << "Масив не містить нульових елементів" << endl;
    else
        cout << "Перший нульовий елемент має номер: " << pos + 1
        << " (індекс " << pos << ")" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    task3();
    task4();
    task5();
    task6();

    return 0;
}