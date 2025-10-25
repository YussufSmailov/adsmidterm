#include<iostream>
#include<vector>


using namespace std;

int main(){
    int n,h; cin >> n >>h;
    vector<int> v(n);
    int mx=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        mx=max(v[i], mx);
    }
    int l=1;
    int r=mx;
    while(l<r){
        int mid=l+(r-l)/2;
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=(v[i]+mid-1)/mid;
        }
        if (cnt<=h)r=mid;
        else l=mid+1;
    }
    cout<<l;
}
// 1 2 3 4 5 6 7