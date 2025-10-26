#include<iostream>
#include<vector>

using namespace std;


void quick_sort(vector<int>& v, int l, int r){
    int i=l;
    int p=v[(l+r)/2];
    int j=r;
    while(i<j){
        while(v[i]<p)i++;
        while(v[j]>p)j--;
        if (i<=j){
            swap(v[i], v[j]);
            i++; j--;
        }
    }
    if (l<j) quick_sort(v, l, j);
    if (i<r) quick_sort(v, i, r);
}





int main(){
    int n, m; cin >> n >> m;
    vector<int>v1; vector<int>v2;
    for(int i=0; i<n; i++){
        int x; cin >> x; v1.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x; cin >> x; v2.push_back(x);
    }
    if (v1.size()==0 || v2.size()==0){
        cout<<' ';
        return 0;
    }
    quick_sort(v1, 0, v1.size()-1);
    quick_sort(v2, 0, v2.size()-1);
    int uk1=0; int uk2=0;




    while(uk1<n && uk2<m){
        if(v1[uk1]<v2[uk2]){
            uk1++;
        }
        else if(v1[uk1]>v2[uk2]){
            uk2++;
        }
        else{
            cout<<v1[uk1]<<" ";
            uk1++; uk2++;
        }
    }
}
