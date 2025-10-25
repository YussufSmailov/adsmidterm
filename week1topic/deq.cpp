#include<iostream>

using namespace std;

struct Node{
    Node*next; Node*prev;
    int data;
    Node(int d): data(d), next(nullptr), prev(nullptr) {} 
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
    void pop_front(){
        Node*temp=front;
        front=front->next;
        if (front==nullptr) rear=nullptr;
        else{
            front->prev=nullptr;
        }
        delete temp;
        sz--;
    }
    void push_back(int d){
        Node*node= new Node(d);
        if (empty()){
            front=rear=node;
        }else{
            rear->next=node;
            node->prev=rear;
            rear=node;
        }
        sz++;
    }
    void pop_back(){
        Node*temp=rear;
        rear=rear->prev;
        if(rear==nullptr) front=nullptr;
        else{
            rear->next=nullptr;
        }
        delete temp;
        sz--;
    }
    int peek_front(){
        return front->data;
    }
    int peek_back(){
        return rear->data;
    }
    bool empty(){
        return sz==0;
    }
    int size(){
        return sz;
    }
};

int main(){
    Deque dq;
    char symb; int num;
    while(symb!='*'){
        cin >> symb >> num;
        if(symb='+') dq.push_front(num);
        if(symb=='-') dq.push_back(num);
        if(symb=='+'){
            if (dq.size()!=1){
                cout<<dq.peek_back()+dq.peek_front();
                dq.pop_back(); dq.pop_front();
            }else if (dq.empty())cout<<"error";
            else{
                cout<<dq.peek_back()*2;
            }
        }
    }
}