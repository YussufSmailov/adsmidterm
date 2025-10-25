#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int cnt=0;
    for(int i=0; i<n; i++){
        if((2*i+1)<n && (2*i+2)<n){
            if (v[(2*i+1)]<v[(2*i+2)]){
                cnt++;
            }
        }
   
}
 cout << cnt;
}