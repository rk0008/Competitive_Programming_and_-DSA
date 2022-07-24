#include <iostream>
#include <string.h>
using namespace std;


        int ceilIdx(int tail[], int l, int r, int key) 
        { 
            while(r>l){
            int m= l+(r-l)/2;
            if(tail[m]>=key){
                r=m;
            }
            else{
                l=m+1;
            }
            }
            return r;
        } 
  
    int LIS(int arr[], int n) 
    { 
     int tail[n];
     tail[0]=arr[0];
     int lis=1;

     for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            tail[i]=arr[lis-1];
            lis++;
        }
        else{
            int c=ceilIdx( tail, 0,  lis-1,  arr[i]) ;
             tail[c]=arr[i];
        }
     }
   
   return lis;
       
    } 


int main() {
	
	
 int arr[] ={3, 10, 20, 4, 6, 7};
  int n = 6;

cout<<LIS(arr, n);
	

}