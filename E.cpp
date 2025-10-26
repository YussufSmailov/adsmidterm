#include<iostream>
#include<vector>
#include<string>
using namespace std;


// void quicksort(int arr[], int l, int r){
//     int p=arr[(l+r)/2];
//     int i=l; int j=r;
//     while(i<j){
//         while(arr[i]<p)i++;
//         while(arr[j]>p)j--;
//         if (i<=j){
//             swap(arr[j], arr[i]);
//             i++; j--;
//         }
//     }
//     if (l<j) quicksort(arr, l,j);
//     if (i<r) quicksort(arr,i, r);


// }
void bubble(vector<int>& arr, int n){
 
    for(int i=0; i<n-1; i++){
        bool swapped=false;
        for(int j=0; j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }

   


}




int main(){
    int n,m ; cin >> n >> m;
    vector<vector<int> > v;
  
    for(int i=0; i<n; i++){
        vector<int> tempa;
        for(int j=0; j<m; j++){
            int x; cin >> x;
            tempa.push_back(x);
        }
        v.push_back(tempa);
    }

    for(int i=0; i<m; i++){
        vector<int> t;
        for(int j=0; j<n; j++){
            t.push_back(v[j][i]);
        }
        bubble(t, t.size());
        for(int j=0; j<n; j++){
            v[j][i]=t[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }

}





