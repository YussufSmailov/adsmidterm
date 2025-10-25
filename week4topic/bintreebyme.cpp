#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void bt_insert(Node*&root, int val){
    if (root==nullptr) {
        root=new Node(val);
        return;}
    else if (val<root->data) bt_insert(root->left, val);
    else bt_insert(root->right, val);
}
Node*find_min(Node*node){
    if (node==nullptr) return NULL;
    while(node->left!=nullptr){
        node=node->left;
    }
    return node;
}
Node*find_max(Node*node){
    if (node==nullptr) return NULL;
    while(node->right!=nullptr){
        node=node->right;
    }
    return node;
}
Node*search(Node*node, int val){
    if (node==nullptr) return nullptr;
    if (node->data=val) return node;
    else if (val<node->data){
        return search(node->left, val);
    }
    else{
        return search(node->right, val);
    }
}
Node*delete_node(Node*node, int val){
    if (node==nullptr) return nullptr;
    if (val<node->data){
        delete_node(node->left, val);
    }
    else if (val>node->data){
        delete_node(node->right, val);
    }else{
        if (node->left==nullptr && node->right==nullptr){
            delete node;
            node=NULL;
        }
        else if(node->right==nullptr){
            Node*temp=node;
            node=node->left;
            delete temp;
        }
        else if(node->left==nullptr){
            Node*temp=node;
            node=node->right;
            delete temp;
        }
        else{
            Node*temp=find_max(node->left);
            node->data=temp->data;
            node->left=delete_node(node->left, node->data);

        }
        return node;
    }
}
int get_height(Node*node){
    if (node==nullptr) return 0;
    return 1 + max(get_height(node->left), get_height(node->right));

}
int countNodes(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }


void inOrder(Node*node){
    if (node==nullptr){
        return;
    }
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}
void preOrder(Node*node){
    if (node==nullptr){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    
    preOrder(node->right);
}
void postOrder(Node*node){
    if (node==nullptr){
        return;
    }
    
    postOrder(node->left);
    
    postOrder(node->right);
    cout<<node->data<<" ";
}




int main(){
    Node*root=NULL;
    vector<int> v={1, 2, 3, 4, 5};
    for(int i=0; i<5; i++){
        bt_insert(root, v[i]);
    }
    cout<<find_max(root)->data;
    cout<<get_height(root);
}