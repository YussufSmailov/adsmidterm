#include<iostream>
#include<vector>

using namespace std;

class MinHeap{
    public:
    vector<int> v;
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int get_min(){ return v[0];}

    void insert(int k){
        v.push_back(k);
        int ind=v.size()-1;
        while(ind>0 && v[ind]<v[parent(ind)]){
            swap(v[ind], v[parent(ind)]);
            ind=parent(ind);
        }
    }

    void heapify(int i){
        if(left(i)>v.size()-1) return;
        int j=left(i);
        if(right(i)<v.size() && v[right(i)]<v[left(i)]){
            j=right(i);
        }
        if (v[i]>v[j]){
            swap(v[i], v[j]);
            heapify(j);
        }
    }
    int extract_min(){
        int root_v=v[0];
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if (v.size()>0){
            heapify(0);
        }
        return root_v;
    }


};


class MaxHeap{
    public:
    vector<int> a;
    int parent(int i){ return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    
    int get_max(){
        return a[0];
    }

    void insert(int k){
        a.push_back(k);
        int ind=a.size()-1;
        while(ind>0 && a[ind]>a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind=parent(ind);
        }
    }
    void heapify(int i){
        if (left(i)>a.size()-1) return;
        int j=left(i);
        if(right(i)<a.size() && a[right(i)]>a[left(i)]){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    int extract_max(){
        int root_v=a[0];
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if (a.size()>0) heapify(0);
        return root_v;
    }

};








int main(){
    MinHeap mpq;
    MaxHeap maxpq;
    for(int i=0; i<6; i++){
        int x; cin >>x; mpq.insert(x); maxpq.insert(x);   
     }
    for(int i=0; i<6; i++){
        cout<<mpq.extract_min()<<" ";
    }
    cout<<'\n';
    for(int i=0; i<6; i++){
        cout<<maxpq.extract_max()<<" ";
    }
}






class MinHeap{
    public:
    vector<int> v;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int getMin(){
        return v[0];
    }
    void insert(int k){
        v.push_back(k);
        int ind=v.size()-1;
        while(ind>0 && v[ind]<v[parent(ind)]){
            swap(v[ind], v[(parent(ind))]);
            ind=parent(ind);
        }
    }
     
    void heapify(int i){
        if(left(i)>v.size()-1) return;
        int j=left(i);
        if(right(i)<v.size() && v[right(i)]<v[left(i)]){
            int j=right(i);
        }
        if(v[i]>v[j]){
            swap(v[i], v[j]);
            heapify(j);
        }
    }



    int extractmin(){
        int root_v=v[0];
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if (v.size()>0){
            heapify(0);
        }
        return root_v;
    }
};







mergeSort(int a[], int l, int r){
    if (l<r){
        int mid=(l+r)/2;
        mergeSort(a, l, mid)
    }
}