#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partion(vector<int> &arr,int start, int end) {
    int pivot = arr[start];
    int PI = end;
    for(int i = end; i > start; i--)
    {
        if(arr[i] >= pivot)
        {
            swap(arr[PI], arr[i]);
            PI--;
        }
    }
    swap(arr[PI], arr[start]);
    return PI;
}

void quickSort(vector <int> &arr, int start, int end) {
	// Complete this function
    if(start >= end)
    return;
    int PI = partion(arr, start, end);
    quickSort(arr, start, PI - 1);
    quickSort(arr, PI+1, end);
    for(int i = start; i <= end; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size() - 1);
    return 0;
}

