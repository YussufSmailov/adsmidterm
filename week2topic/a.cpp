#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    Node*next;
    int data;
    Node(int d): data(d), next(nullptr) {}
};

struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }
    void insert(int d){
        Node*node=new Node(d);
        if (head==nullptr) {head=node; return;}
        Node*cur=head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=node;

    }
    void traverse(int f){
        int min=10000000;
        Node*cur=head;
        int var;
        int index=0;
        int min_index;
        while(cur){
            var=abs(f-cur->data);
            if (var<min){
                min=var;
                min_index=index;
            }
            index++;
            cur=cur->next;
        }
        cout<<min_index;
    }
};


int main(){
    int n; cin >> n;
    LinkedList ll;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        ll.insert(x);
    }
    int f; cin >> f;
    ll.traverse(f);

}

