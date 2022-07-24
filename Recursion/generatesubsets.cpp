#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 void generatesusbset(string s,string s1,int n){

    if(n==s.length()){
        cout<<s1<<" ";
        return;
    }
  generatesusbset(s,s1,n+1);
  generatesusbset(s,s1+s[n],n+1);

    
 }
     
     
     

     

    
 


 
 
 
int main() 
{    
 string str = "ABC";
    	
    generatesusbset(str, "", 0);

     
 
    
 
    return 0;
}