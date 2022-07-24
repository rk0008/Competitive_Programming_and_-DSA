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
 void displayinorder(node* root){
     if(root== NULL){
         return;
     }
     
     displayinorder(root->left);
     cout<<root->key<<" ";
     displayinorder( root->right);
     
 }

  void displaypreorder(node* root){
     if(root== NULL){
         return;
     }
     cout<<root->key<<" ";
     displaypreorder(root->left);
     displaypreorder( root->right);
     
 }


  void displaypostorder(node* root){
     if(root== NULL){
         return;
     }
     
     displaypostorder(root->left);
     displaypostorder( root->right);
     cout<<root->key<<" ";
     
 }

 int treeheight(node* root){
     if(root==NULL){
         return 0;
     }

     return max(treeheight( root->left),treeheight(root->right)) + 1;
 }

 void printnodesatdistK(node* root,int k){
     if(root==NULL){
         return;
     }
     if(k==0){
         cout<<root->key<<" ";
     }
     else{
         printnodesatdistK( root->left, k-1);
         printnodesatdistK(root->right,k-1);

     }

    
 }

 void printlevelorder(node* root,int k){
     if(root==NULL){
         return;
         queue<node *> q;
         q.push(root);

         while(q.empty()==false){
             node* curr= q.front();
             q.pop();
             cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
         }

     }

  

     
     
     

     

    
 }


 
 
 
int main() 
{    
    node* root=new node(10);
    root->left= new node(20);
    root->right= new node(30);
    root->right->left= new node(40);
    root->right->right= new node(50);
    
   // displayinorder( root);
   // displaypreorder( root);
   // displaypostorder( root);

   //cout<<treeheight(root)<<endl;

  // printnodesatdistK( root, k);
  //printlevelorder(root,k);


     
 
    
 
    return 0;
}