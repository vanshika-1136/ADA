#include <iostream>
#include <vector>
using namespace std;

void generateArray(double **arr, int n, int m)
{
    // srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int wt = rand() % 200 + 20;
        int profit = rand() % 1000 + 100;
        arr[i][0] = wt;
        arr[i][1] = profit;
        // arr[i][2] = (double)arr[i][1]/arr[i][0];
    }
}
void printArray(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int partition(double **arr, int low, int high, int m) {
    double pivot = arr[high][0];  // Using the wt for sorting
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] <= pivot) {  // Sort in sscending order by profit
            i++;
            
            for (int p = 0; p < m; p++) {
                swap(arr[i][p], arr[j][p]);
            }
        }
    }

    for (int p = 0; p < m; p++) {
        swap(arr[i + 1][p], arr[high][p]);
        
    }
    return i + 1;
}
void quickSort(double **arr, int low, int high, int m) {
    if (low < high) {
        int p = partition(arr, low, high, m);
        quickSort(arr, low, p - 1, m);
        quickSort(arr, p + 1, high, m);
    }
}
vector<double> fractionalKnapsack(double **arr, int n, int capacity) {
    int weight = 0;
    double profit = 0;
    vector<double> List(n, 0);
    int i = 0;

    // Pick items in full until the knapsack is full
    while (i < n && weight + arr[i][0] <= capacity) {
        weight += arr[i][0];
        profit += arr[i][1];
        List[i] = 1;
        i++;
    }

    // If there is remaining capacity, pick the fraction of the next item
    if (i < n) {
        int remWt = capacity - weight;
        double fraction = (double)remWt / arr[i][0];
        profit += fraction * arr[i][1];
        List[i] = fraction;
    }

    cout << "Total weight: " << weight << " for " << i << " items." << endl;

    cout << "Total profit: " << profit << " for " << i << " items." << endl;

    return List;
}

void result(double **arr, int n, int capacity) {
    vector<double> list = fractionalKnapsack(arr, n, capacity);
    for (int i = 0; i < list.size(); i++) {
        cout << "Item no. " << i + 1 << "'s fraction: " << list[i] << endl;
        if (list[i] == 0) {
            break;
        }
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int m = 2;  // We have 3 columns (weight, profit)
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];  // Create an array of n rows and 3 columns
    }

    generateArray(arr, n, m);  // Fill the array with random values

    cout << "Sorting by weight in increasing order using QuickSort" << endl;
    quickSort(arr, 0, n - 1, m);  // Sort based on profit (arr[i][1])
    
    cout << "Weight\tProfit\t" << endl;
    printArray(arr, n, m);

    int capacity = 1000;
    result(arr, n, capacity);

    

    return 0;
}