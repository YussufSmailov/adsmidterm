#include<iostream>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): left(nullptr), right(nullptr), data(d) {}
};

void insert(Node*&root, int val){
    if (root==NULL){
        root=new Node(val);
        return;
    }
    if (val<root->data){
        return insert(root->left, val);
    }else{
        return insert(root->right, val);
    }
}

int diameter=0;

int depth(Node*node){
    if (node==nullptr){
        return 0;
    }
    int L=depth(node->left);
    int R=depth(node->right);
    int diameter=max(diameter, L+R);
    return 1+max(L,R);
}