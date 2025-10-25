#include<iostream>

#include<vector>

using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int x): data(x), left(nullptr), right(nullptr){}
};

void bt_insert(Node*&root, int val){
    if (root==nullptr){
        root = new Node(val);
        return;
    }
    else{
        if (val<root->data) bt_insert(root->left, val);
        else bt_insert(root->right, val);
    }
}

Node*find_mind(Node*node){
    if(node==nullptr) return NULL;
    while(node->left != nullptr){
        node=node->left;
    }
    return node;
}

Node*find_max(Node*node){
    if(node==nullptr) return NULL;
    while(node->right != nullptr){
        node=node->right;
    }
    return node;
}

Node*search(Node*node, int val){
    if (node==nullptr) return nullptr;
    if (node->data==val) return node;
    if (val<node->data) return search(node->left, val);
    else return search(node->right, val);
}

Node*delete_node(Node*node, int val){
    if (node==nullptr) return nullptr;
    if (val<node->data){
         delete_node(node->left, val);}
    else if (val>node->data) {
        delete_node(node->right, val);}
    else{
        // Case 1: Node has no children (leaf node)
        if (node->right==NULL && node->left==NULL){
            delete node;
            node=NULL;
        }
        // Case 2: Node has only right child
        if (node->left==NULL){
            Node*temp=node;
            node=node->right;
            delete temp;
        }
         // Case 3: Node has only left child
        else if (node->right==NULL){
            Node*temp=node;
            node=node->left;
            delete temp;
        }
        // Case 4: Node has both children
        else{
            Node*temp=find_max(node->left);
            node->data=temp->data;
            node->left=delete_node(node->left, temp->data);

        }
        return node;
    }
}




int main(){
    Node*root=NULL;
    vector<int> v = {6, 2, 13, 3, 5, 7, 8, 1};
    for(int i=0; i<v.size(); i++){
        bt_insert(root, v[i]);
    }

}


