#include<iostream>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr){}
};
void bt_insert(Node*&root, int val){
    if (root==nullptr) {
        root=new Node(val);
        return;}
    else if (val<root->data) bt_insert(root->left, val);
    else bt_insert(root->right, val);
}
int height(Node*node){
    if(node==nullptr) return 0;
    else{
        return 1+max(height(node->left), height(node->right));
    }
}
Node*find(Node*node, int x){
    if (node->data==x) return node;
    else if (x<node->data) return find(node->left, x);
    else return find(node->right, x);

}
int count(Node*node){
    if (node==nullptr){
        return 0;
    }
    return 1+count(node->left) + count(node->right);
}

int main(){
     int n,m;
    cin >> n;
    Node*root=NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        bt_insert(root, x);
    }
    cin >> m;
    Node*c=find(root,m);
    cout<<count(c);
}