#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v (n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int ind, val;
        cin >> ind >> val;
        v[ind-1]+=val;
    }
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i]);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}