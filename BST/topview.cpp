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

 void mapfill(Node* root,int hd,map<int,int> &mp){
     if(root==NULL){
         return;
     }
     mapfill(root->left,hd-1,mp);
     mp[hd]=root->key;
     mapfill(root->right,hd+1,mp);


 }



void topview(Node* root){
    
    map<int,int> mp;
    mapfill(root,0,mp);

    for(auto x:mp){
        cout<<x.second<<" ";
    }

   
}


void topView(Node *root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        if(mp.find(hd)==mp.end())
            mp[hd]=(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}



void bottomView(Node *root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
            mp[hd]=(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}

 
int main() 
{    
 
		Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    bottomView(root);
   




    
 
    return 0;
}