#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n; cin >> n;
    stack<int> st;
    int max=-10000;
    while(n--){
        string comanda;
        int val;
        cin >> comanda >> val;
        if (comanda=="insert"){
            if (val>max){
                max=val;
                st.push(max);
            }else{
                if (!st.empty()){
                    int temp=st.top();
                    st.pop();
                    st.push(val);
                    st.push(temp);
                }
            }
        }
    }
}