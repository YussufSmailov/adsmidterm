#include<iostream>
#include<stack>
#include<vector>
#include<deque>
using namespace std;
int main(){
    stack<int> st;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int var; cin >> var;
        while(!st.empty() && st.top()>=var){
            st.pop();
        }
        if(st.empty()){
            cout<<"-1"<<" ";
        }else{
            cout<<st.top();
        }
        st.push(var);
    }
    
   
}