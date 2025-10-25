#include<iostream>
 
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void insert(Node*&root, int val){
    if(root==NULL){
        root=new Node(val);
        return ;

    }
    if(val<root->data){
        return insert(root->left, val);
    }else{
        return insert(root->right, val);
    }
}
int sum=0;
void traverse(Node*root){
    if(root==nullptr){
        return;
    }
    traverse(root->left);
    if(root->left && root->right){
        sum++;
    }
    traverse(root->right);
}

int main(){
    int n;
    cin >> n;
    Node*root=NULL;
    for(int i=0; i<n;i++){
        int x; cin >> x;
        insert(root, x);
    }
    traverse(root);
    cout<<sum;
}