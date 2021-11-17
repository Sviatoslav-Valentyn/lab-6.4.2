// Варіант 6(Рекурсивний спосіб)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Init(int* b, const int size, int i)
{
    if (i < size)
    {
        b[i] = -2 + rand() % 5;
        return Init(b, size, i + 1);
    }
}

void Print(int* b, const int n, int i)
{
    cout << setw(4) << b[i];
    if (i < n - 1)
    {
        Print(b, n, i + 1);
    }
    else
        cout << endl;

}

int Min(int* b, const int n, int i, int min)
{
    if (b[i] < min)
        min = b[i];
    if (i < n - 1)
        return Min(b, n, i + 1, min);
    else
        return min;
}
int FirstElement(int* b, const int n, int i)
{
    if (i < n)
    {
        if (b[i] > 0)
            return b[i];
        else
            return FirstElement(b, n, i + 1);
    }
    return -1;
}

int LastElement(int* b, const int n, int i)
{
    if (i < n)
    {
        if (b[i] > 0)
            return b[i];
        else
            return LastElement(b, n, i + 1);
    }
    return 1;
}

int Sum(int b[], const int n, int i)
{
    int s = 0;
    for (int i = 1 + FirstElement(b, n, 0); i < LastElement(b, n, 0); i++)
        s += b[i];
    return s;
}

int Nadx0(int* b, const int size, int i)
{
    if (b[i] == 0)
        return i;
    if (i < size - 1)
        return Nadx0(b, size, i + 1);
    else
        return -1;
}

void Sort(int* a, const int size, int i)
{
    if (i < size - 1)
    {
       int index = Nadx0(a,size,i);
       if (index != -1)
       {
           int tmp = a[i];
           a[i] = a[index];
           a[index] = tmp;
       }
    Sort(a, size, i + 1);
    }
}

int main()
{
    SetConsoleOutputCP(1251);

    srand(time(0));
    int n;
    cout << "n = "; cin >> n;

    int* b = new int[n];
    Init(b, n, 0);
    Print(b, n, 0);
    cout << "Мінімальний елемент = " << Min(b, n, 0, 0) << endl;
    cout << "Суму елементів масиву = " << Sum(b, n, 0) << endl;
    Sort(b, n, 0);
    Print(b, n, 0);


    delete[] b;
    b = nullptr;

    return 0;
}