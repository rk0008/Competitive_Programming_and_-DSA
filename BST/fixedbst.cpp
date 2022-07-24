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

Node *prevv=NULL,*first=NULL,*second=NULL;

 void inorder(Node* root){
     if(root== NULL){
         return;
     }
     
    inorder(root->left);
     cout<<root->key<<" ";
     inorder( root->right);
     
 }

void fixbst(Node* root){
         if(root==NULL){
             return ;
         }
         fixbst(root->left);
         if(prevv!=NULL && root->key<prevv->key){
             if(first==NULL){
                 first=prevv;
             }
                 second=root;
             
         }
         prevv= root;
         fixbst(root->right);
}




 
int main() 
{    
 
 Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
   inorder(root); 
    cout<<endl;
    fixbst(root);
    int temp=first->key;
    first->key=second->key;
    second->key=temp;
    inorder(root);
          
    return 0;  

	

 
    
 
    return 0;
}