#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 struct node{
     int key;
     node* right;
     node* left;
     node(int n){
         key=n;
         right=NULL;
         left=NULL;
     }

 };

 
bool search(node* root,int x){
    if(root==NULL){
        return false;
    } 
    if(root->key==x){
        return true;
    }

     else if(root->key>x){
    search(root->left,x);
       }

     else if(root->key<x){
    search(root->right,x);
          }


}

 
bool searchiterative(node* root,int x){
    if(root==NULL){
        return false;
    } 

    while(root!=NULL){
    if(root->key==x){
        return true;
    }

     else if(root->key>x){
         root=root->left;
       }

     else if(root->key<x){
        root= root->right;
          }

    }
}

node *insert(node* root,int val){

    if(root==NULL){
        return new node(val);
    } 
   

      if(root->key>val){
    root->left=insert(root->left,val);
       }

     else if(root->key<val){
       root->right=insert(root->right,val);
          }

          return root;

}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}

node *insert(node* root,int val){

   node *temp=new node(val);
   node *parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>val)
            curr=curr->left;
        else if(curr->key<val)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>val)
        parent->left=temp;
    else
        parent->right=temp;
    return root;

}
 
 
 
int main() 
{    
    node *root=new node(15);
	root->left=new node(5);
	root->left->left=new node(3);
	root->right=new node(20);
	root->right->left=new node(18);
	root->right->left->left=new node(16);
	root->right->right=new node(80);
	int x=22;
    
  
   root=insert(root,x);
   inorder(root);


 
    
 
    return 0;
}