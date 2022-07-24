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

 bool findPath(node* root,vector<node*> &p,int n){
     if(root==NULL){
         return false;
     }
     p.push_back(root);
     if(root->key==n){
         return true;
     }

     if(findPath( root->left,p, n) || findPath( root->right,p, n)){
         return true;
     }
     else{
         p.pop_back();
     }

     return false;


 }
 

node* lca(node* root,int n1,int n2){

    vector <node *> path1, path2;
    if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
        return NULL;
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    return NULL;

}


int countNode(node *root){
    int lh=0,rh=0;
    node *curr=root;
    while(curr!=NULL){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL){
        rh++;
        curr=curr->right;
    }
    if(lh==rh){
        return pow(2,lh)-1;
    }else{
        return 1+countNode(root->left)+countNode(root->right);
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
    //printspiral(root);
   

    int n1=40,n2=50;
	
	node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
     
 
    
 
    return 0;
}