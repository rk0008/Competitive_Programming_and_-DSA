#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s) 
{ 
    //   bool visited[V];
    //   	for(int i = 0; i < V; i++) 
	// 	visited[i] = false; 
    //   queue<int>q;
    //   visited[s]=true;
    //   q.push(s);

    //   while(q.empty()==false){
    //       int curr=q.front();
    //       q.pop();
    //       cout << curr << " "; 
    //       for(auto x: adj[curr]){
    //                if(visited[x]==false){
    //                      visited[x]=true;
	// 	        q.push(x);
    //                }
    //       }


    //   }

    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    queue<int>q;
    visited[s]=true;
    q.push(s);

    while(q.empty()==false){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto x:adj[curr]){
            if(visited[x]=false){
                visited[x]=true;
                q.push(x);
            }
        }
    }


} 



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); 

	return 0; 
} 
