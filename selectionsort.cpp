#include<iostream>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i], arr[min]);
        }
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
    selectionSort(arr, size);
}