#include<iostream>

using namespace std;

int arr[100];


void quicksort(int l, int r){
    int p=arr[(l+r)/2];
    int i=l;
    int j=r;
    while(i<j){
        while(arr[i]<p)i++;
        while(arr[j]>p)j--;
        if (i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    }
    if(l<j){
        quicksort(l, j);

    }
    if (i < r){
        quicksort(i, r);
    }
    
    
};


int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    quicksort(0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
}