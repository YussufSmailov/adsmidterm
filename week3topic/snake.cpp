#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<int>&v, int cnt, int x){
    int l=0;
    int r=v.size()-1;
    if (cnt%2==0)
    while(l<=r){
        int mid = l+(r-l)/2;
        if (v[mid]==x) return true;
        if (v[mid]<x) l=mid+1;
        else r=mid- 1;
    }else{
        while(l<=r){
        int mid = l+(r-l)/2;
        if (v[mid]==x) return true;
        if (v[mid]<x) r=mid-1;
        else l=mid+1;
    }
    
}
    return false;
}
// 1 2 3 4 5 6
// 6 5 4 3 2 1

int main(){
    int n, a,m; cin >> a;
    vector<int> f;
    for(int i=0; i<a; i++){
        int x; cin>>x;
        f.push_back(x);
    }
    cin >> n >> m;
    
    vector<vector<int> > v;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<m; j++){
            int x; cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    int cnt=0;
    for(int i=0; i<a; i++){
        cnt=0;
        while(cnt!=n){
            vector<int> temp;
            for(int j=0; j<m; j++){
                temp.push_back(v[cnt][j]);
                if(binary_search(temp, cnt, f[i])){
                    cout<<cnt<<' '<<j<<' ';
                    break;
            }
            }
            temp.clear();
            cnt++;
        }
        cout<<endl;
    }
}