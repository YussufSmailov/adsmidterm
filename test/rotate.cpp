#include<iostream>

using namespace std;

struct Node{
    Node*next;
    int data;
    Node(int d): next(nullptr), data(d) {}
};

struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }
    void insert(int d){
        Node*node=new Node(d);
        Node*cur=head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=node;
    }
    void shift(int n){
        
        for(int i=0; i<n; i++){
            Node*cur=head;
        while(cur->next->next){
            cur=cur->next;
        }
        Node*temp=cur->next;
        temp->next=head;
        head=temp;
        cur->next=NULL;
    }
}
};