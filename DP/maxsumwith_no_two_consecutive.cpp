#include <iostream>
#include <limits.h>
using namespace std;

int maxSum(int arr[], int n)
{
	int dp[n+1];
    
    dp[1]=arr[0];
    dp[2]=max(arr[0],arr[1]);

    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],arr[i-1]+dp[i-2]);
    }

	return dp[n];
}


int main() {
    
    	int n = 5, arr[]= {10, 20, 30, 40, 50};
    	
    	cout<<maxSum(arr, n);
    	
    	return 0;
}