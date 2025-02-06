 #include<iostream>
 using namespace std;
 #include <vector>

  int f(vector<int> &arr){
    int n =arr.size();
    if(n==1){
        return 0;
    }
    if (arr[n-1]>arr[n-2]){
        return n-1;
    }
    if (arr[0]>arr[1]){
        return 0;
    }

    int low=1;
    int high =n-2;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            return mid;
        }
        else if(arr[mid-1]>arr[mid]){
        high=mid-1;
        }
        else{
            low=mid+1;
        }
        return -1;
    }

  }
  int main(){
    int n;
    cout<<" enter size of array: "<<n;
    
    vector<int> arr(n);
    int ans =f(arr);
    cout<<"index of peak: "<< ans<<endl;
    cout<<"element at peak: "<<arr[ans]<<endl;
    return 0;
  }