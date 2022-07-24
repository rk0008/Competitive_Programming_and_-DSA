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


 bool checkbst(Node* root,int min,int max ){
        if(root==NULL){
            return true;
        }

       return ( root->key>min && root->key<max && 
            checkbst(root->left,min,root->key) && checkbst(root->right,root->key,max));  
 }

int prevv=INT_MAX;
  bool isbst(Node* root ){
      if(root==NULL){
          return true;
      }
      if(isbst(root->left)==false){
          return false;
      }

      if(root->key<prevv){
          prevv=root->key;
      }
       
       return isbst(root->right);
         
 }


 
int main() 
{    
 
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	

    if(checkbst(root,INT_MIN,INT_MAX))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";
	

 
    
 
    return 0;
}