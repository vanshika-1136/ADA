#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
// arr[i][0] = arrrival time, arr[i][1] = finish time, arr[i][3]= duration
void generateArray(double **arr, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int arrival = rand() % 200 + 20;
        int finish = rand() % 200 + 40;
        while(finish<=arrival){
            finish = rand() % 200 + 40;
        }
        arr[i][0] = arrival;
        arr[i][1] = finish;
        arr[i][2] =finish-arrival;
    }
}

int partition(double **arr, int low, int high, int k, int m)
{
    double pivot = arr[low][k];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i][k] <= pivot)
        {
            i++;
        };
        while (j > low && arr[j][k] > pivot)
        {
            j--;
        };
        if (i < j)
        {
            for (int p = 0; p < m; p++)
            {
                swap(arr[i][p], arr[j][p]);
            }
        }
    };
    for (int p = 0; p < m; p++)
    {
        swap(arr[low][p], arr[j][p]);
    }
    return j;
}
void quickSort(double **arr, int low, int high, int k, int m)
{
    if (low < high)
    {
        int p = partition(arr, low, high, k, m);
        quickSort(arr, low, p - 1, k, m);
        quickSort(arr, p + 1, high, k, m);
    }
}

void printArray(double **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
vector<double> maxProcesses(double **arr, int n, int m)
{
    int totalDuration = 500;//in seconds
    vector<double> finalList(n, 0);
    int i = 0;
    int dur=0;
    while (dur + arr[i][2] <= totalDuration)
    {
            dur+= arr[i][2];
            finalList[i] = 1;
            i++;
    }
   
    if (totalDuration - dur > 0)
    {
        cout << "More process can be processed for "<<totalDuration-dur<<"seconds\n";
    }

    cout<<"Total "<<i<<" processes processed in "<<dur<<"seconds."<<endl;
    return finalList;
}

void result(double**arr, int n, int m){
    auto start = high_resolution_clock::now();
    vector<double> list = maxProcesses(arr, n, m);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "The duration is " << duration.count() << " milliseconds" << endl;
  
}

int main()
{
    int n;
    int m=3;
    cout << "Enter row and columns for matrix:\n";
    cin >> n ;
    double **arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[m];
    }
    generateArray(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort Arrival Time"<<endl;
    quickSort(arr, 0, n - 1, 0, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    
    cout<<"--------------------------"<<endl;
    cout<<"Sort Finish"<<endl;
    quickSort(arr, 0, n - 1, 1, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort duration"<<endl;
    quickSort(arr, 0, n - 1, 2, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    return 0;
}