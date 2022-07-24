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

void treetolist(Node* root, vector<int> &list){
             
             if (root == NULL) 
            return; 
  
        treetolist(root->left, list); 
        list.push_back(root->key); 
       treetolist(root->right, list); 

}








 bool ispairpresent(Node* root, int target){
   
     vector<int> a2; 
  
        treetolist(root, a2); 
  
        int start = 0; 
  
        int end = a2.size() - 1;  
  
        while (start < end) { 
  
            if (a2[start] + a2[end] == target)  
            { 
                cout<<"Pair Found: " << a2[start] << " + " << a2[end] << " "
                                   << "= " << target; 
                return true; 
            } 
  
            if (a2[start] + a2[end] > target) // decrements end 
            { 
                end--; 
            } 
  
            if (a2[start] + a2[end] < target) // increments start 
            { 
                start++; 
            } 
        } 
  
        cout<<"No such values are found!"; 
        return false;

 }


bool isPairSum(Node *root, int sum, unordered_set<int> &s) 
    { 
        if(root==NULL)return false;
        
        if(isPairSum(root->left,sum,s)==true)
            return true;
            
        if(s.find(sum-root->key)!=s.end())  
            return true;
        else
            s.insert(root->key);
        return isPairSum(root->right,sum,s);
    }




 








 
int main() 
{    
 
 Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
   
 
  ispairpresent(root,74);
 


    /* int sum=33;
    unordered_set<int> s;    
    cout<<isPairSum(root,sum,s);*/
          

    
 
    return 0;
}