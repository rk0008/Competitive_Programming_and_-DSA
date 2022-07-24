#include <iostream>
using namespace std;

int sol(int arr[], int n)
{
	int dp[n][n];

	for(int i=0;i<n;i++){
        dp[i][i+1]=max(arr[i],arr[i+1]);
    }

    for(int gap=3;gap<n;gap+=2){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
            dp[i][j]=max(arr[i]+ min(dp[i+2][j],dp[i+1][j-1]),arr[j]+ min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

	return dp[0][n-1];
}


int main() {
    
    	int n = 4;

		int arr[] = {20, 5, 4, 6};
		
    	cout<<sol(arr, n);
    	
    	return 0;
}
