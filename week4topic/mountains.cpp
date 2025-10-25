#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Node{
    Node*right;
    Node*left;
    int data;
    Node(int d): data(d), right(nullptr), left(nullptr) {}
};
void bt_insert(Node*&root, int val){
    if (root==nullptr){
        root=new Node(val);
    }
    else if (val<root->data){
        return bt_insert(root->left, val);
    }else{
        return bt_insert(root->right, val);
    }
}
bool travel(Node*root, string s){
    int n=s.size();
    Node*node=root;
    for(int i=0; i<n; i++){
        if (node==nullptr) return false;
        char com=s[i];
        if (com=='L') node=node->left;
        else node=node->right;
    }
    if (node==nullptr) return false;
    else return true;
}


int main(){
    int n,m;
    cin >> n >> m;
    Node*root=NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        bt_insert(root, x);
    }
    for(int i=0; i<m; i++){
        string s; cin >> s;
        if(travel(root, s)){
            cout<<"yes";
        }else{
            cout<<"no";
        }
    }
}