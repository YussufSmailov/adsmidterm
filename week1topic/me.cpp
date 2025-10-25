#include<iostream>

using namespace std;

struct Node{
    int data;
    Node*next; Node*prev;
    Node(int d): data(d), next(nullptr), prev(nullptr){}
};

struct Stack{
    Node*top; int sz;
    Stack(){
        top=nullptr; sz=0;
    }
    void push(int d){
        Node*node=new Node(d);
        node->next=top;
        top=node;
        sz++;
    }
    void pop(){
        Node*temp=top;
        top=top->next;
        delete top;
        sz--;
    }
    int peek(){
        return top->data;
    }
};

struct Queue{
    Node*rear; Node*front; int sz;
    Queue(){
        rear=nullptr;
        front=nullptr;
        sz=0;
    }
    void push(int d){
        Node*node=new Node(d);
        if (empty()){
            front=rear=node;
        }else{
            rear->next=node;
            rear=node;
        }
    }
    void pop(){
        Node*temp=front;
        front=front->next;
        if(front==nullptr) rear=nullptr;
        delete temp;
        sz--;
    }
    int peek(){
        return front->data;
    }
    bool empty(){
        return sz==0;
    }

};

struct Deque{
    Node*front; Node*rear; int sz;
    Deque(){
        front=rear=nullptr;
        sz=0;
    }
    void push_front(int d){
        Node*node=new Node(d);
        if (empty()){
            front=rear=node;
        }else{
            node->next=front;
            front->prev=node;
            front=node;
        }
        sz++;
    }
    void push_back(int d){
        Node*node=new Node(d);
        if (empty()){
            front=rear=node;
        }else{
            node->prev=rear;
            rear->next=node;
            rear=node;
        }
        sz++;
    }
    void pop_front(){
        Node*temp=front;
        front=front->next;
        if(front==nullptr) rear=nullptr;
        else{
            front->prev=nullptr;
        }
        sz--;
        delete temp;
    }
    void pop_back(){
        Node*temp=rear;
        rear=rear->prev;
        if (rear==nullptr) front = nullptr;
        else{
            rear->next=nullptr;
        }
        delete temp;
        sz--;
    }
    bool empty(){
        return sz==0;
    }
}




int main(){

}