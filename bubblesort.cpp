#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
};


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        int x; cin >> x;
        arr[i]=x;
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
}