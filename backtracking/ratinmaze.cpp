#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 bool isbool(vector<vector<int>> arr,vector<vector<int>> &vis,int x,int y,int a){
    if((x>=0 && x<a ) && (y>=0 && y<a)  && arr[x][y]!=0 && vis[x][y]!=1)
    return true;
    else
    return false;
 }

 void solve(vector<vector<int>> arr,vector<vector<int>> &vis,int x,int y,int &ans,int a){
  if(x==a-1 && y==a-1){
    ans++;
    ans=ans%1000000007;
    return;
  }
  

  if(isbool(arr,vis,x+1,y,a)){
   vis[x][y]=1;
   solve( arr,vis, x+1,y,ans,a);
   vis[x][y]=0;
  }
   

    if(isbool(arr,vis,x,y+1,a)){
   vis[x][y]=1;
    solve( arr,vis, x,y+1,ans,a);
   vis[x][y]=0;
     }
  }
 
int main() 
{    
 
 int a,b;
 cin>>a>>b;

  vector<vector<int>> arr;
for(int i=0;i<a;i++){
  vector<int> v;
    for(int j=0;j<a;j++)
    v.push_back(1);
arr.push_back(v);
}

int q=a/2;
arr[q][q]=0;

for(int i=1;i<=b;i++){
    for(int j=q-i;j<=q+i;j++){
    arr[j][q-i]=0;
     arr[j][q+i]=0;
}
  for(int j=q-i;j<=q+i;j++){
    arr[q-i][j]=0;
     arr[q+i][j]=0;
}
}




int ans=0;
vector<vector<int>> vis;

for(int i=0;i<a;i++){
  vector<int> v;
    for(int j=0;j<a;j++){
    v.push_back(0);
}
vis.push_back(v);
}




 solve(arr,vis,0,0,ans,a);


 cout<< ans<<endl;


	
	



 
    
 
    return 0;
}