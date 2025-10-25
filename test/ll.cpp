#include<iostream>

struct Node{
    int data;
    Node*next;
    Node(int d): next(nullptr), data(d) {}
};

struct LL{
    Node*head;
    LL(){
        head=nullptr;
    }
    void append(int d){
        Node*node=new Node(d);
        
    } 
}