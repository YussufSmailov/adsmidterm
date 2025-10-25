#include<iostream>

using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int d): data(d), next(nullptr){}
};

struct Queue{
    Node*front; Node*rear; int sz;
    Queue(){
        front = nullptr;
        rear = nullptr;
        sz=0;
    }
    void push(int data){
        Node*node=new Node(data);
        if(rear==nullptr){
            front=rear=node;
        }else{
            rear->next=node;
            rear=node;
        }
        sz++;
    }
    void pop(){
        Node*temp=front;
        front=front->next;
        if(front==nullptr) rear = nullptr;
        delete temp;
    }


    int peek(){
        return front->data;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return sz==0;
    }
};


int main(){
    Queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    while(!q.empty()){
        int a=q.peek();
        cout<<a;
        q.pop();
    }
}