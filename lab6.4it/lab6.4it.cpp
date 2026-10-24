
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Обчислює кількість елементів, що дорівнюють нулю
int CountZeros(const double a[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0.0)
            count++;
    }

    return count;
}

// Обчислює суму елементів після першого мінімального елемента
double SumAfterMinimum(const double a[], int n)
{
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[minIndex])
            minIndex = i;
    }

    double sum = 0.0;

    for (int i = minIndex + 1; i < n; i++)
        sum += a[i];

    return sum;
}

// Сортує елементи на непарних місцях за зростанням їхніх модулів
void SortOddPositionsByAbs(double a[], int n)
{
    int count = (n + 1) / 2;

    for (int pass = 0; pass < count - 1; pass++)
    {
        for (int j = 0; j < count - pass - 1; j++)
        {
            int i1 = 2 * j;
            int i2 = 2 * (j + 1);

            if (fabs(a[i1]) > fabs(a[i2]))
            {
                double temp = a[i1];
                a[i1] = a[i2];
                a[i2] = temp;
            }
        }
    }
}

// Виводить масив в одному рядку
void PrintArray(const double a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(8) << a[i];

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (!cin || n <= 0)
    {
        cout << "The number of elements must be positive."
            << endl;
        return 1;
    }

    double* a = new double[n];

    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (!cin)
    {
        cout << "Invalid input." << endl;
        delete[] a;
        return 1;
    }

    cout << "Original array:" << endl;
    PrintArray(a, n);

    cout << "Number of zeros: "
        << CountZeros(a, n) << endl;

    cout << "Sum after minimum element: "
        << SumAfterMinimum(a, n) << endl;

    SortOddPositionsByAbs(a, n);

    cout << "Array after sorting odd positions by "
        << "absolute value:" << endl;
    PrintArray(a, n);

    delete[] a;

    return 0;
}

