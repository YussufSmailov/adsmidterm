#include<iostream>
#include<map>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr){}
};
int bt_insert(Node*&root, int val){
    int level=1;
    Node*cur=root;
    if (root==nullptr) {
        root=new Node(val);
        return 1;}
    while (true){
        if (val<cur->data){
            if (cur->left==nullptr){
                cur->left=new Node(val);
                return level+1;}
            else{
                cur=cur->left;
                level++;
            }   
        }else{
            if (cur->right==nullptr){
                cur->right=new Node(val);
                return level+1;
            }else{
                cur=cur->right;
                level++;
            }
        }
    }
    
}
int height(Node*node){
    if (node==nullptr){
        return 0;
    }
    return 1+max(height(node->left), height(node->right));
}



int main(){
    Node*root=nullptr;
    int n; cin >> n;
    map<int, int>m;
    for(int i=0; i<n;  i++){
        int x; cin >> x;
        int level=bt_insert(root, x);
        m[level]+=x;
    }
    cout<<height(root)<<endl;
    map<int,int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        cout<<it->second<<" ";
    }
    
    
}