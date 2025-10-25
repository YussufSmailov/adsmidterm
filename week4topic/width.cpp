#include<iostream>
#include<queue>
using namespace std;
struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};


Node*find(Node*node, int val){
    if (node==nullptr){
        return NULL;
    }
    if (node->data=val) return node;
    if (val<node->data){
        return find(node->left, val);
    }else{
        return find(node->right, val);
    }

}


void bt_insert(Node*&root, int x, int y, int z){
    if(root==nullptr){
        root=new Node(x);
        return;
    }
    
    if (z==0){
        root->left=new Node(y);
    }else{
        root->right=new Node(y);
    }
}

int shirina(Node*root){
    queue<Node*> q;
    Node*node=root;
    q.push(node);
    int ans=-1;
    while(!q.empty()){
        int sz=q.size();
        ans=max(ans, sz);
        for(int i=0; i<sz; i++){
            Node*r=q.front(); q.pop();
            if (r->right) q.push(r->right);
            if (r->left) q. push(r->left);
        }
    }
    return ans;
}




int main(){
    int n; cin >> n;
    Node*root=NULL;
    for(int i=0; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        bt_insert(root, x, y, z);
    }
    cout<<shirina(root);
}