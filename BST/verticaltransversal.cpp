#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 struct Node{
     int key;
     Node* right;
     Node* left;
     Node(int n){
         key=n;
         right=NULL;
         left=NULL;
     }

 };

 



void vtransversal(Node* root){

    map<int, vector<int>> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(q.empty()==false){
        auto p=q.front();
        Node* curr= p.first;
        int hd=p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left!=NULL ){
            q.push({curr->left,hd-1});
        }
         if(curr->right!=NULL ){
            q.push({curr->right,hd+1});
        }
    }
     
        for(auto x:mp){
        for(int y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }

   
}






 
int main() 
{    
 
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    vtransversal(root);
   




    
 
    return 0;
}