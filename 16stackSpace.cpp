#include <iostream>
using namespace std;
// #include "../headers/array1D.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

void generateArray(int arr[], int n) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

static int space = 0;
static int maxSpace= 0;
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {

        while (arr[i] <= pivot && i <= high)
        {
            i++;
        };

        while (arr[j] > pivot && j > low)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    };
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        space++;
        maxSpace= max(maxSpace,space);
        cout<<"Space "<<space<<endl;
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
        space--;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter size of the array" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    generateArray(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    cout<<"Max Space used is "<<maxSpace<<endl;
    return 0;
}