#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void quick_sort(vector<int>& v, int l, int r){
    if (l>r) return ;
    int i=l;
    int j=r;
    int p=v[(l+r)/2];
    while(i<=j){
        while(v[i]<p)i++;
        while(v[j]>p)j--;
        if (i<=j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
     if(l<j){
        quick_sort(v, l, j);

    }
    if (i < r){
        quick_sort(v, i, r);
    }

}


void build(vector<int>&v, int l, int r, vector<int>&a){
    if (l>r) return;
    int mid=(l+r)/2;
    a.push_back(v[mid]);
    build(v, mid+1, r, a);
    build(v, l, mid-1, a);
}



int main(){
    int n;
    cin >> n;
    int s = (1 << n) - 1;
    vector<int> v;
    
    for(int i=0; i<s; i++){
        int x; cin >> x; v.push_back(x);
    }
    quick_sort(v, 0, v.size()-1);
    vector<int> nw;
    build(v, 0, v.size()-1, nw);
    for(int i=0; i<nw.size(); i++){
        cout<<nw[i]<<" ";
    }
}