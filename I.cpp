#include<iostream>
#include<string>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n=s.size();
    for(int i=0; i<n; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(s[min]>s[j]){
                min=j;
            }
        }
        if (min!=i){
            swap(s[i], s[min]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<s[i];
    }
}