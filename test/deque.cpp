#include<iostream>
using namespace std;
struct Node{
    Node*next;
    Node*prev;
    int data;
    Node(int d): next(nullptr), data(d), prev(nullptr) {}
};

struct Deque{
    Node*front;
    Node*rear;
    int sz;
    Deque(){
        front=rear=nullptr;
        sz=0;
    }
    void push_f(int d){
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
    void push_b(int d){
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
        if (empty()){
            return;
        }
        else if (front==nullptr) rear=nullptr;
        else front->prev=nullptr;
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
        sz--;
    }
    bool empty(){
        return sz==0;
    }
};


int main(){
   
}