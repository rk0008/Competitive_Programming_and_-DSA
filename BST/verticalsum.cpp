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

void vsum(Node* root,int hd, map<int,int> &mp){
     if(root==NULL)return;
         vsum(root->left,hd-1,mp);
    mp[hd]+=root->key;
    vsum(root->right,hd+1,mp);
}




void verticalsum(Node* root){
    map<int,int> mp;

    
           
        vsum(root,0,mp);
       for(auto it: mp){
           cout<<it.second<<" ";
       }

}

 








 
int main() 
{    
 
 Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
   
 verticalsum(root);




    
 
    return 0;
}