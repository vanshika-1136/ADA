#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
using namespace chrono;
using namespace std;

void generateArray(int **arr, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int wt = rand() % 200 + 20;
        int profit = rand() % 1000 + 100;
        arr[i][0] = wt;
        arr[i][1] = profit;
    }
}

int partition(int **arr, int low, int high)
{
    int pivot = arr[low][0];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i][0] <= pivot)
        {
            i++;
        };
        while (j > low && arr[j][0] > pivot)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i][0], arr[j][0]);
            swap(arr[i][1], arr[j][1]);
        }
    };
    swap(arr[low][1], arr[j][1]);
    swap(arr[low][0], arr[j][0]);
    // printArray(arr, high+1, 2);

    return j;
}
void quickSort(int **arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
