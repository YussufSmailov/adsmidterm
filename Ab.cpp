#include<iostream>
#include<string>
using namespace std;

char v[100000];
char c[100000];

void bubble(char arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped=false;
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }

    for(int i=0; i<n; i++) cout<<arr[i];
   

}






int main(){
    int n; cin >> n;
    int cnt_v=0;
    int cnt_c=0;
    
    string s; cin >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
            v[cnt_v]=s[i];
            cnt_v++;
        }
        else{
            c[cnt_c]=s[i];
            cnt_c++;
        }
    }

    bubble(v,  cnt_v);
    bubble(c,  cnt_c);
    
}


