#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& arr, int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    return i;
}

void quickSort(vector<int>& arr, int low, int high){
    if (low < high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    cout << "The sorted array is: ";
    for (int i=0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}