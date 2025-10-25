#include<iostream>
#include<vector>


using namespace std;

int main(){
    int n,m; cin >> n >>m;
    vector<int> v;
 
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if (i==0) v.push_back(x);
        else{
            v.push_back(v[i-1]+x);
        }
    }
    vector<int> mis;
    for(int i=0; i<m; i++){
        
        int x; cin >> x;
        mis.push_back(x);
    }
    
    for(int i=0; i<m; i++){
        int l=0;
        int r=v.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if (mis[i]<=v[mid]){
                r=mid;
            }
            else l=mid+1;
        }
        cout<<(l+1)<<endl;
    }

}