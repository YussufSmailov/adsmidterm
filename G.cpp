#include<iostream>
#include<map>
#include<string>

using namespace std;
int main(){
    int n;
    cin >> n;
    map<string, string> m;
    string old, newk;
    map<string, string>::iterator it;
    for(int i=0; i<n; i++){
        bool found=false;
        cin >> old >> newk;
            
            for(it=m.begin(); it!=m.end(); it++){
                if (it->second==old){
                    m[it->first]=newk;
                    found = true;
                }
            }
            if (!found) m[old]=newk;
    }
        
    
    cout<<m.size()<<endl;
    for(it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<' '<<it->second<<endl;
    }
}