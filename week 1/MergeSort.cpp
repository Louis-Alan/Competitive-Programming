#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) 
{  
  int s1 = q - p + 1;
  int s2 = r - q;
  int L[s1], M[s2];

  for (int i = 0; i < s1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < s2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < s1 && j < s2) 
  {
    if (L[i] <= M[j]) 
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < s1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < s2) 
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void print(int arr[], int size) 
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() 
{
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = 6;

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  print(arr, size);
  return 0;
}