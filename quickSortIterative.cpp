#include <iostream>
using namespace std;
#include <stack>

int partition (int arr[],int low,int high){
    int i=low;
    int pivot=arr[low];
    int j=high+1;
    do{
     do{
        i++;
     }while(arr[i]<=pivot && i <= high);
     do{
        j--;
     }while(arr[j]>pivot && j >= low);
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }while (i<j);
    swap(arr[j],arr[low]);
    return j;
}
void quickSortIterative(int arr[],int low,int high){
   stack<int> s;
   s.push(low);
   s.push(high);

   while(!s.empty()){
    high=s.top();
    s.pop();
    low=s.top();
    s.pop();
    int pi=partition(arr,low,high);
    if(pi-1>low){
        s.push(low);
        s.push(pi-1);
    }
    if(pi+1<high){
        s.push(pi+1);
        s.push(high);
    }
   }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform Iterative Quick Sort
    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}