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