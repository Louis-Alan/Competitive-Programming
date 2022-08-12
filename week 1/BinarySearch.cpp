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
	int item, size;
	cout<<"Enter size: ";
	cin>>size;
	int arr[size];
	cout<<"Enter Array elements: ";
	for(int i = 0; i < size; i++)
		cin>>arr[i];
	cout<<"Enter item to search: ";
	cin>>item;
	cout<<endl;
	
	int result = bSearch(arr, 0, size - 1, item);
	if(result == -1)
		cout<<"Element not present";
	else
		cout<< "Element is present at position " << result << endl;
}
