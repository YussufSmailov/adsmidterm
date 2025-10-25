#include<iostream>

struct Node{
    Node*next;
    int data;
    Node(int d): next(nullptr), data(d) {}
};

struct Stack{
    Node*top;
    int sz;
    Stack(){
        top=nullptr;
        sz=0;
    }
    void push(int d){
        if (empty()){
            top=new Node(d);
        }else{
            Node*node=new Node(d);
            node->next=top;
            top=node;
        }
        sz++;
    }
    void pop(){
        if (empty()){
            return;
        }else{
            Node*temp=top;
            top=top->next;
            sz--;
            delete temp;
        }
    }
    int peek(){
        return top->data;
    }
    bool empty(){
        return sz==0;
    }
    int size(){
        return sz;
    }
};


int main(){
    Stack st;
}