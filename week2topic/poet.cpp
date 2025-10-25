#include<iostream>
#include<string>
using namespace std;



struct Node{
    Node*next;
    string data;
    Node(string d): data(d), next(nullptr){}
};

struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }
    void insert(string d){
        Node*node=new Node(d);
        if (head==nullptr){
            head=node;
            return;
        }
        Node*cur=head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=node;
    }
    void shift(int l){
      
        Node*cur=head;
        int i=1;
        while(cur){
            if (i>l){
                cout<<cur->data<<" ";
            }
            i++;
            cur=cur->next;
        }
        Node*newc=head;
        i=1;
        while(newc){
            if (i<=l){
                cout<<newc->data<<" ";
            }
            i++;
            newc=newc->next;
        }
        
    }
};


int main(){
    int n,m; cin >> n >> m;
    string s;
    LinkedList ll;
    for(int i=0; i<n; i++){
        cin >> s;
        ll.insert(s);
    }
    ll.shift(m);

}