#include<iostream>

using namespace std;

int a[100];

void merge(int a[], int left,int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[1000]; int R[1000];
    for(int i=0; i<n1; i++){
        L[i]=a[left+i];
    }
    for(int i=0; i<n2; i++){
        R[i]=a[mid+i+1];
    }
    int k=left;
    int i=0; int j=0;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        k++; i++;
    }
    while(j<n2){
        a[k]=R[j];
        k++; j++;
    }
}

void merge_sort(int a[], int left, int right){
    if (left<right){
        int mid=(left+right)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}


void mergeS(int a[], int l, int r, int mid){
    int n1=mid-l+1;
    int n2=r-mid;
    int L1[1000];
    int R1[1000];
    for(int i=0; i<n1; i++)
        L1[i]=a[l+i];
    for(int i=0; i<n1; i++)
        R1[i]=a[mid+i+1];
    int k=l;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if (L1[i]<=R1[j]){
            a[k]=L1[i];
            i++;
        }else{
            a[k]=R1[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=L1[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=R1[j];
        k++;
        j++;
    }
}





void mergeSort(int a[], int l, int r){
    if (l<r){
        int mid=(l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        mergeS(a, l, r, mid);
    }
}








int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    mergeSort(a, 0, n-1);
     for(int i=0; i<n; i++)
        cout << a[i]<<" ";
}