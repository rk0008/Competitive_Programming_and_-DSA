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

void printKth(Node* root,int k,int count){
    while(root!=NULL){
        	printKth(root->left,k,count);
            count++;
            if(count==k){
                cout<<root->key;
                return;
            }
            printKth(root->right,k,count);
    }
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
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printKth(root,k,count);


 
    
 
    return 0;
}