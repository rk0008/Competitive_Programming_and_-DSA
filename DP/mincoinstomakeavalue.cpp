#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;


       
  int minCoins(int arr[], int m, int value) 
    { 
      
    int dp[value+1];
    dp[0]=0;

    for(int i=1;i<=m;i++){
        dp[i]=INT_MAX;
    }

    for(int i=1;i<=value;i++){

        for(int j=0;j<m;j++){
           if(arr[j]<=i){
            int subres=dp[i-arr[j]];
           if(subres!=INT_MAX){
            dp[i]=min(dp[i],subres+1);
           }
           }

        }
    }
    return dp[value];
          
    }  


int main() {
	
int arr[] = {7, 2, 1}, val =5, n =3;

cout<<minCoins(arr, n, val);
	

}