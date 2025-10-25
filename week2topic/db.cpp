#include<iostream>

using namespace std;

struct Node{
    Node*next; Node*prev; string data;
    Node(string d): next(nullptr), prev(nullptr), data(d){}
};

struct DoubleLinkedList{
    Node*head; Node*tail;
    DoubleLinkedList(){
        head=tail=nullptr;
    }
    void add_front(string info){
        Node*node=new Node(info);
        if (head==nullptr){
            head=tail=node;
            cout<<"ok"<<endl;;
            return;
        }else{
            node->next=head;
            head->prev=node;
            head=node;
            cout<<"ok"<<endl;;
            return;
        }
    }
    void add_back(string info){
        Node*node= new Node(info);
        if(tail==nullptr){
            head=tail=node;
            cout<<"ok"<<endl;;
            return;
        }
        else{
            tail->next=node;
            node->prev=tail;
            node=tail;
            cout<<"ok"<<endl;;
            return;
        }
    }
    void erase_front(){
        if(head==NULL){
            cout<<"error"<<endl;
            return;
        }
        Node*temp=head;
        
        string df=head->data;
        head=head->next;
        head->prev=nullptr;
        
        delete temp;
        cout<< df<<endl;
    }
    void erase_back(){
        Node*temp=tail;
        if (tail==nullptr){
            cout<<"error<<endl;";
            return;
        }
        string dm=tail->data;
        tail=tail->prev;
        delete temp;
        cout<< dm << endl;
    }
    void front(){
        if (head==nullptr){
            cout<<"error"<<endl;;
            return;
        }else{
            cout<<head->data<<endl;;
        }
    }
    void back(){
        if (tail==nullptr){
            cout<<"error"<<endl;;
            return;
        }else{
            cout<<tail->data<<endl;;
        }
    }
    void erase(){
        Node*cur=head;
        while(cur){
            Node*temp=cur;
            cur=cur->next;
            delete temp;
        }
        cout<<"ok"<<endl;
    }
    string exit(){
        return "goodbye";
    }
};

int main(){
    DoubleLinkedList ll;
    while(true){
        string comand, info; cin >> comand>>info;
        if (comand=="add_front") ll.add_front(info);
        if (comand=="add_back") ll.add_back(info);
        if (comand=="erase_front") ll.erase_front();
        if (comand=="erase_back") ll.erase_back();
        if (comand=="front") ll.front();
        if (comand=="back") ll.back();
        if (comand=="clear") ll.erase();
        if (comand=="exit") break;
    }
}