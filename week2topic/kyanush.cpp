#include<iostream>
#include<string>
using namespace std;



struct Node{
    Node*next;
    int data;
    Node(int d): data(d), next(nullptr){}
};

struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }
    void insert(int d){
        Node*node=new Node(d);
        if (head==nullptr){
            head=node;
            return;
        }
        Node*cur=head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=node;
    }
    void shift(){
        int i=0;
        Node*cur=head;
        while(cur){
            if (i%2==0){
                cout<<cur->data;
            }
            cur=cur->next;
            i++;
        }
    }
};

int main(){
    int n; cin >> n;
    LinkedList ll;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        ll.insert(x);
    }
    ll.shift();
}