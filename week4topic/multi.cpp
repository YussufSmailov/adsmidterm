#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void insert(Node*&root, int val){
    if (root==nullptr){
        root=new Node(val);
        return;
    }
    if (val<root->data){
        return insert(root->left, val);
    }else{
        return insert(root->right, val);
    }
}

Node*min(Node*node){
    if (node==nullptr){
        return NULL;
    }
    while(node->left){
        node=node->left;
    }
    return node;
}
Node*maxi(Node*node){
    if (node==nullptr){
        return NULL;
    }
    while(node->right){
        node=node->right;
    }
    return node;
}

Node*find(Node*node, int val){
    if (node==nullptr){
        return NULL;
    }
    if (node->data==val){
        return node;
    }
    if (val<node->data){
        return find(node->left, val);
    }else{
        return find(node->right, val);
    }
}
Node* del(Node*root, int val){
    if (root==nullptr) return nullptr;
    if (val<root->data) root->left = del(root->left, val);
    else if (val>root->data)
    {
        root->right=del(root->right, val);
    }
    if (root->left==NULL && root->right==NULL){
        return root;
        delete root;
    }
    else if (root->left==NULL && root->right!=NULL){
        Node*temp=root;
        root=root->right;
        delete root;
    }
    else if(root->right==NULL &&root->left!=NULL){
        Node*temp=root;
        root=root->left;
        delete root;
        
    }else{
        Node*c=maxi(root->left);
        root->data=c->data;
        root->left=del(root->left, c->data);
    }
    return root;
}

int main(){
    int n; cin >> n;
    map<int, int> m;
    Node*root=NULL;
    vector<int>v;
    for(int i=0; i<n; i++){
        string command; int val;
        cin >> command >> val;
        if (command=="insert"){
            if (m[val]==0){
                m[val]++;
                insert(root, val);
            }else{
                m[val]++;
            }
        }
        else if (command=="delete"){
            if (m[val]>1){
                m[val]--;
            }else{
                del(root, val);
                m[val]--;
            }
        }else{
            v.push_back(m[val]);
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}