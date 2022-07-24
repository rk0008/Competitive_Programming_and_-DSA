#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 int ropecutting(int n,int a,int b,int c){

     if(n==0){
         return 0;
     }
     
     if(n<0){
         return -1;
     }
    int res=max(ropecutting(n-a,a,b,c),max(ropecutting(n-b,a,b,c),ropecutting(n-c,a,b,c)));

    if(res==-1){
        return -1;
    }
    
    return res+1;

 }
     
     
     

     

    
 


 
 
 
int main() 
{    
    	int n = 5, a = 2, b = 1, c = 5;
	
	cout<<ropecutting(n, a, b, c);

     
 
    
 
    return 0;
}