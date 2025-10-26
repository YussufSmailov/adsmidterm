#include<iostream>
#include<vector>
#include<map>
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
    if (n==0 || m==0) {
        cout<<' ';
        return 0;
    }
    map<int, int> mp;
    int x;
    for(int i=0; i<n; i++){
         cin >> x; 
        mp[x]++;
    }
    vector<int> v;
    for(int i=0; i<m; i++){
        cin >> x;
        if (mp[x]){
            v.push_back(x);
            mp[x]--;
        }
    }
    
    quick_sort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}