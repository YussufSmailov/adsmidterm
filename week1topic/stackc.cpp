#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr){}
};

struct Stack{
    Node *top;
    int sz;
    Stack(){
        top=nullptr;
        sz=0;
    }


void push(int data){
    Node*node=new Node(data);
    node->next = top;
    top = node;
    sz++;

}

void pop(){
    if (top!=nullptr){
        Node*temp=top;
        top=top->next;
        delete temp;
        sz--;
    }
}

int topn(){
    if (!empty())
        return top->data;
}
int size(){
    return sz;
}
bool empty(){
    return sz==0;
}

};

int main(){
    Stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    while(!st.empty()){
        int a=st.topn();
        cout<<a;
        st.pop();
    }

}