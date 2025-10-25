#include<iostream>

using namespace std;

struct Node{
    Node*next;
    int data;
    Node(int d): data(d), next(nullptr) {}
};

struct LinkedList{
    Node*head;
    int sz;
    LinkedList(){
        head=nullptr;
        sz=0;
    }
    void push_back(int d){
        Node*node=new Node(d);
        if(head==nullptr) head=node;
        else{
            Node*cur=head;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            cur->next=node;
        }
        sz++;
    }
    void pop_back(){
        Node*cur=head;
        while(cur->next->next!=NULL){
            cur=cur->next;
        }
        delete cur->next;
        cur->next=nullptr;
        sz--;
    }
    void add_front(int d){
        Node*node=new Node(d);
        node->next=head;
        head=node;
        sz++;
    }
    void pop_front(){
        if (head==NULL) return;
        Node*cur=head;
        head=head->next;
        delete cur;
        sz--;
    }
    void print_list(){
        Node*cur=head;
        while(cur!=NULL){
            cout<<cur->data<<"->";
            cur=cur->next;
        }
    }
    int size(){
        return sz;
    }
    void del(int d){
        Node*cur=head;
        while(cur->next->data!=d){
            cur=cur->next;
        }
        Node*temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
    }
    void reverse(){
        Node*prev=nullptr;
        Node*cur=head;
        while(cur){
            Node*next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }head=prev;
    }
};

int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.del(3);
    ll.reverse();
    ll.print_list();

    ll.size();

}