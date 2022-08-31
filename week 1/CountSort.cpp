#include <bits/stdc++.h>
using namespace std;

void countSort(int a[], int n)
{
    int output[10];
    int count[10];
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

int main()
{
    // int n;
    // cout << "Enter n of arr: ";
    // cin >> n;
    // cout << "Enter elements of arr:\n";
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    int n = 6;
    int a[] = {6, 2, 7, 6, 9, 1};
    countSort(a, n);
    cout << "a is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    return 0;
}