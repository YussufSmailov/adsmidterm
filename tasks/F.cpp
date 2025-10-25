#include<iostream>
#include<queue>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void bt_insert(Node*&root, int val){
    if(root==nullptr){
        root=new Node(val);
        return;
    }else if (val<root->data){
        bt_insert(root->left, val);
    }else{
        bt_insert(root->right, val);
    }
}
int sum=0;


void travel(Node*root){
    queue<Node*> q;
        q.push(root);
    int level=0;

    while(!q.empty()){


        int sz=q.size();
        for(int i=0; i<sz; i++){
            Node*cur=q.front(); q.pop();
            if(cur->left){
             q.push(cur->left);
            }
            if(cur->right) q.push(cur->right);
        }
        level++;
        for(int i=0; i<q.size(); i++){
            Node*first=q.front();
            q.pop();
            sum+=(first->data-level);
            q.push(first);
       
        }

        
    }
}



int main(){
    Node*root=NULL;
    int n; cin >> n;
    int f;
    for(int i=0; i<n; i++){
        
        int x; cin >> x;
        if (i==0){
            f=x;
        }
        bt_insert(root, x);
    }
    travel(root);
    cout<<sum+f;
}