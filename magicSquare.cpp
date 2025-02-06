#include <iostream>
#include<vector>
using namespace std;
void generateMagicSquare(int** arr, int n){
    // vector<vector<int>>magicSquare(n,vector<int>(n,0));
    int i=0 ,j=n/2;
    arr[i][j]=1;
     for(int k=2;k<=n*n;k++){
     int a = i - 1;
        int b = j - 1;

        if (a < 0)
        {
            a = n - 1;
        }
        if (b < 0)
        {
            b = n - 1;
        }
        if (a < 0 && b < 0)
        {
            a = i + 1;
            b = j;
        }
        if (arr[a][b] != 0)
        {
            a = i + 1;
            b = j;
        }
        arr[a][b]=k;
        i = a;
        j = b;

    //  arr[i][j]=k;
     
     }
     
}
void print(int** arr, int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout << "Enter size of matrix " << endl;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Magic Square is possible only with odd matrix.";
        return 0;
    }
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]();
    }
    generateMagicSquare(arr, n);
    print(arr, n );
    return 0;
}