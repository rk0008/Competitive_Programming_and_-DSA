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
 


 void printspiral(node* root){

      if(root==NULL)
      return;

      stack<node *> s1;
      stack<node *> s2;
       
       s1.push(root);

       while(s1.empty()==false || s2.empty()==false){

           while(s1.empty()==false){
               node *curr=s1.top();
               s1.pop();
               cout<<curr->key;
             
                if(curr->right!=NULL){
                   s2.push(curr->right);
               }
                 if(curr->left!=NULL){
                   s2.push(curr->left);
               }
           }

             while(s2.empty()==false){
               node *curr=s2.top();
               s2.pop();
               cout<<curr->key;
               if(curr->left!=NULL){
                   s1.push(curr->left);
               }
                if(curr->right!=NULL){
                   s1.push(curr->right);
               }
           }


       }

 }
int res=0;
 int diameter(node* root){
     if(root==NULL)
     return 0;
    
    int lh=diameter(root->left);
    int rh=diameter(root->right);

    res=max(res,1+lh+rh);
    
        return 1+max(lh,rh);

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
    //printspiral(root);
    cout<<res;

     
 
    
 
    return 0;
}