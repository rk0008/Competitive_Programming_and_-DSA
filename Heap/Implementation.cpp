#include<bits/stdc++.h>
using namespace std;
#define ll long
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
 
 struct MinHeap{
     int *arr;
     int size;
     int capacity;

     MinHeap(int c){
         size=0;
         capacity=c;
         arr = new int[c];
         
     }
      int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    void insert(int x){
        if(size==capacity)
        return;
        size++;
        arr[size-1]=x;
        
        for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];){ 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }

    void minHeapify(int i){
             int lt=left(i);
             int rt=right(i);
             int smallest;
             if(lt < size && arr[i]>arr[lt]){
                 smallest=lt;
             }
               if(rt < size && arr[smallest]>arr[rt]){
                 smallest=rt;
             }
             if(smallest!=i){
                 swap(smallest,i);
                 minHeapify(smallest);
             }
    }

     int extractMin() 
    { 
    if (size <= 0) 
        return INT_MAX; 
    if (size == 1) 
    { 
        size--; 
        return arr[0]; 
    }  
    swap(arr[0],arr[size-1]);
    size--; 
    minHeapify(0); 
  
    return arr[size]; 
    }

  
  void decreasekey(int i, int x){
      arr[i]=x;
      while(i!=0 && arr[parent(i)]>arr[i]){
          swap(arr[i],arr[parent(i)]);
          i=parent(i);
      }
    minHeapify(i);
  }
    
    void deleteKey(int i) 
    { 
        decreasekey(i, INT_MIN); 
        extractMin(); 
    }
     
     
   void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }
     


  







    
 };

 
int main() 
{    
  MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
	

 
    
 
    return 0;
}