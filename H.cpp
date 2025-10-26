#include<iostream>
using namespace std;

char a[100];

void quicksort( char a[], int l, int r){
    char p=a[(r+l)/2];
    int i=l;
    int j=r;
    while(i<j){
        while(a[i]<p)i++;
        while(a[i]>p)j--;
        if (i<=j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if(l<j)quicksort(a, l,j);
    if(i<r)quicksort(a,i,r);
}


int main(){
    int n; cin >> n;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    char k; cin >> k;
    //quicksort(a, 0, n-1);
    for(int i=0; i<n; i++){
        if (a[i]>k) {cout<<a[i]; return 0;}
    }
    cout<<a[0];
}