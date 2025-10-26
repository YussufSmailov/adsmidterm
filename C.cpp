#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using namespace std;



// void selection_sort(int a[], int n){
//     for(int i=0; i<n-1; i++){
//         int min = i;
//         for(int j=i+1; j<n; j++){
//             if (a[j]<a[min]){
//                 min = j;
//             }
//         }
//         if (min!=i) swap(a[i], a[min]);
//     }
// }
void quick_sort(vector<int>& a, int l, int r){
    int p=a[(l+r)/2];
    int i=l;
    int j=r;
    while(i<j){
        while(a[i]<p)i++;
        while(a[j]>p)j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if(l<j) quick_sort(a, l, j);
    if(i<r) quick_sort(a, i, r);
}





int main(){
    vector<int> a;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x; a.push_back(x);
    }
    quick_sort(a, 0, n-1);
    map<pair<int, int>, int>m;
    vector<int> diff;

    for(int i=0; i<n-1; i+=1){
        int temp=abs(a[i]-a[i+1]);
        diff.push_back(temp);
        m[make_pair(a[i], a[i+1])]=temp;
    }

    quick_sort(diff, 0, n-2);
    int min=diff[0];
    map<pair<int, int>, int>::iterator it;

    for(it=m.begin(); it!=m.end(); it++){
        if(it->second==min){
            cout<<it->first.first<<" "<<it->first.second<<" ";
        }
    }
}