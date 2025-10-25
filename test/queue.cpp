#include<iostream>
using namespace std;
struct Node{
    Node*next;
    int data;
    Node(int d): next(nullptr), data(d) {}
};

struct Queue{
    Node*front;
    Node*rear;
    int sz;
    Queue(){
        front=rear=nullptr;
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
        sz++;
    }
    void pop(){
        if (empty()){
            return;
        }else{
            Node*temp=front;
            front=front->next;
            delete temp;
        }
        if (front==nullptr) rear = nullptr;
        sz--;
    }

    int peek(){
        return front->data;
    }
    bool empty(){
        return sz==0;
    }
    int size(){
        return sz;
    }
};


int main(){
   Queue q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);
   while(!q.empty()){
        cout<<q.peek();
        q.pop();
   }
}