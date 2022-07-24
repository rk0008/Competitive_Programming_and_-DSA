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













void printlevelorderlinebyline(node* root){
     if(root==NULL){
         return;
         queue<node *> q;
         q.push(root);
         q.push(NULL);

         while(q.size()>1){
             node* curr= q.front();
             q.pop();
            
             if(curr==NULL){
                 cout<<endl;
                 q.push(NULL);
                 continue;
             }
            
              cout<<curr->key<<" ";
             
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
         }

     }
}
 

void printLevel(node *root){
    if(root==NULL)return;
    queue<node *>q;
    q.push(root);
    while(q.empty()==false){
        int count =q.size();
        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
                cout<<curr->key<<" ";
             
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        }
        cout<<endl;
    }
}  

int sizeofBt(node* root){
    if(root==NULL){
        return 0;
    }

     return sizeofBt(root->left) + sizeofBt(root->right) + 1;
        
}

int maxinbt(node* root){
    if(root==NULL){
        return 0;
    }
    return max(root->key,max(maxinbt(root->left),maxinbt(root->right)));
}


void printleftview(node* root){
   
}


void printLeft(node *root){
    if(root==NULL)
        return;
        queue<node *> q;q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}


bool childrensumproperty(node* root){
    if(root==NULL )
        return true;
  if(root->left==NULL && root->right==NULL)
        return true;

        int sum=0;

        if(root->left!=NULL){
            sum+= root->left->key;
        }
         if(root->right!=NULL){
            sum+= root->right->key;
        }

        return (root->key==sum && childrensumproperty(root->left) && childrensumproperty(root->right));


    
}

int  checkbalancedbt(node* root){
    if(root==NULL )
        return 0;

       int x=checkbalancedbt( root->left) + 1 ;
      int y= checkbalancedbt(root->right) + 1 ;

        if((x-y) >2){
            return 0;
        }
        else
        return 1;

}

int isBalanced(node *root){
    if(root==NULL)
        return 0;
    int lh=isBalanced(root->left);
    if(lh==-1)return -1;
    int rh=isBalanced(root->right);
    if(rh==-1)return -1;
    
    if(abs(lh-rh)>1)
        return -1; 
    else
        return max(lh,rh)+1;
}

int maxwidthbt(node*root){
    if(root==NULL)
    return 0;
    
    queue<node *> q;
    q.push(root);
    int ans=0;

    while(q.empty()==false){
        int count=q.size();
        ans=max(ans,count);
        

        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }

    }

    return ans;

}

node *BTTODLL(node *root){
     if(root==NULL)return root;
    static node* prev=NULL;
    node *head=BTTODLL(root->left);
    if(prev==NULL){
        head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }


  prev=root;
    BTTODLL(root->right);
    return head;




}






  


 
 
 
int main() 
{    
    node* root=new node(10);
    root->left= new node(20);
    root->right= new node(30);
    root->right->left= new node(40);
    root->right->right= new node(50);
    
  
  //printlevelorderlinebyline(root);
 //displaypostorder(root);
 //printLevel(root);
 //cout<<sizeofBt(root);
  //cout<< maxinbt(root);

 // cout<<childrensumproperty(root);
 //cout<<checkbalancedbt(root);
 //cout<<maxwidthbt(root);
  
  node *head=BTTODLL(root);

    
 
    return 0;
}