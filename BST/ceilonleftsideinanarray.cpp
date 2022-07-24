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


 
 void printCeiling(int arr[],int n){
     set<int> s;
     cout<<"-1"<<" ";
     s.insert(arr[0]);
     
     for(int i=1;i<n;i++){
           if(s.lower_bound(arr[i])!=s.end())
            cout<<*(s.lower_bound(arr[i]))<<" ";
        else
            cout<<"-1"<<" ";
        s.insert(arr[i]);
    }

 }
 
 
 
int main() 
{    
 
 int arr[]={2,8,30,15,25,12};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printCeiling(arr,n);


 
    
 
    return 0;
}