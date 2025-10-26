#include<iostream>
#include<string>
using namespace std;

char v[100000];
char c[100000];

void quicksort(char arr[], int l, int r){
    int p=arr[(l+r)/2];
    int i=l; int j=r;
    while(i<j){
        while(arr[i]<p)i++;
        while(arr[j]>p)j--;
        if (i<=j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (l<j) quicksort(arr, l,j);
    if (i<r) quicksort(arr,i, r);

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

    quicksort(c, 0, cnt_c-1);
    quicksort(v, 0, cnt_v-1);
    for(int i=0; i<cnt_v; i++){
        cout<<v[i];
    }
    for(int i=0; i<cnt_c; i++){
        cout<<c[i];
    }
}


