#include<bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int l, int r, int item)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == item)
			return mid;

		if (arr[mid] > item)
			return bSearch(arr, l, mid - 1, item);

		return bSearch(arr, mid + 1, r, item);
	}
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int item = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = bSearch(arr, 0, n - 1, item);
	if(result == -1)
		cout<<"Element not present";
	else
		cout<< "Element is present at position " << result<<endl;
}
