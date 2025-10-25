#include<iostream>
#include<vector>

using namespace std;



void quicksort(vector<int>&v, int l, int r){
    int p=v[(l+r)/2];
    int i=l; int j=r;
    while(i<j){
        while(v[i]<p)i++;
        while(v[j]>p)j--;
        if (i<=j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (l<j){
        quicksort(v, l, j);
    }
    if (i<r){
        quicksort(v, i, r);
    }
}




quicksort(vector<int>&v, int l, int r){
    int p=v[l+r]/2;
    int i=l; int j=r;
    while(i<j){
        while(v[i]<p)i++;
        while(v[j]>p)j--;
        if (i<=j){
            swap(v[i], v[j]);
            i++; j++;
        }
    }
    if (l<j) quicksort(v, l, j);
    if (i<r) quicksort(v, i ,r);
}




int main(){
    // vector<int> v ={5, 1, 14, -5, 6, 7, 3};
    // quicksort(v, 0, v.size()-1);
    // for(int i=0; i<v.size(); i++)
    //     cout<<v[i]<<" ";
     vector<int> v ={5, -3, 17, 2, 0 , 13, 1};
     mergesort(v, 0, v.size()-1);
     for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}