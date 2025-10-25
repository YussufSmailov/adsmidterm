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
    void at_pos(int dat, int pos){
        Node*cur=head;
        Node*node=new Node(dat);
        int i=0;
        while(cur){
            if (i==pos-1){
                node->next=cur->next;
                cur->next=node;
                break;
            }
            cur=cur->next;
            i++;
        }
    }
    void print(){
        Node*cur=head;
        while(cur){
            cout<<cur->data<<' ';
            cur=cur->next;
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
    int dat; int pos;
    cin >> dat >> pos;
  
    ll.at_pos(dat, pos);
    ll.print();

}