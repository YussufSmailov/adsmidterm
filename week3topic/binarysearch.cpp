#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int>& v, int x){
    int l=0; int r=v.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if (v[mid]==x) return x;
        if (v[mid]<x) l=mid+1;
        else r=mid-1;

    }
}




int main(){
    int n; cin >> n;
    vector<int>v;
    for(int i=0; i<n; i++){
        int x; cin >> x; v.push_back(x);
    }
    cout<<binary_search(v, 13);

}