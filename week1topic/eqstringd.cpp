#include<iostream>
#include<stack>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    string a,b;
    ss>>a>>b;
    stack<char> s1; stack<char> s2;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='#'){
            s1.pop();
       
        }else{
        s1.push(a[i]);
    }
    }
    for(int i=0; i<b.size(); i++){
        if(b[i]=='#'){
            s2.pop();
        }else{
        s2.push(b[i]);
    }
    }
    if(s1.size()!=s2.size()) cout<<"no";

        while (!s1.empty() && !s2.empty()){
            if (s1.top()!=s2.top()){
                cout<<"no";
                return 0;
            }
            s1.pop(); s2.pop();
        }
    
    cout<<"yes";
}