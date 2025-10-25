#include<iostream>
#include<vector>

using namespace std;


void quick_sort(vector<int>&v, int l, int r){
    int p=v[(l+r)/2];
    int i=l; int j=r;
    while(i<j){
        while(v[i]<p)i++;
        while(v[j]>p)j--;
        if (i<=j){
            swap(v[i], v[j]);
            i++; j--;
        }
    }
    if (l<j) quick_sort(v, l , j);
    if (i<r) quick_sort(v, i, r);
}


void merge(vector<int>&a, int l, int r, int mid){
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0; i<n1; i++){
        L[i]=a[i+l];
    }
    for(int i=0; i<n2; i++){
        R[i]=a[mid+i+1];
    }
    int uk1=0; int uk2=0; int k=l;
    while(uk1<n1 && uk2<n2){
        if (L[uk1]<=R[uk2]){
            a[k]=L[uk1];
            uk1++;
        }else{
            a[k]=R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1<n1){
        a[k]=L[uk1];
        k++; uk1++;
    }
     while(uk2<n2){
        a[k]=R[uk2];
        k++; uk2++;
    }
}

void mergesort(vector<int>&a, int l, int r){
    if (l<r){
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, r, mid);
    }
}







int main(){
    // vector<int> v={5, 3, -1, 12, 9, 4, 3, 0};
    // quick_sort(v, 0, v.size()-1);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    vector<int> a = {5, 3, -1, 12, 9, 4, 3, 0};
    mergesort(a, 0, a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}