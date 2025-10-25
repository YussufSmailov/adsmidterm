#include<iostream>

using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int d): data(d), next(nullptr), prev(nullptr) {}
};

struct DoubleLL{
    Node*head; Node*tail; 
    DoubleLL(){
        head=tail=nullptr;
    }

    void push_back(int d){
        Node*node=new Node(d);
        if (head==nullptr){
            head=tail=node;
        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }
    void push_front(int d){
        Node*node=new Node(d);
        node->next=head;
        head->prev=node;
        head=node;
    }
    void del_back(){
        Node*temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
    }
    void del_front(){
        Node*temp=head;
        if(head->next=nullptr) delete head;
        else{
            head=head->next;
            head->prev=nullptr;
        }
    }

};