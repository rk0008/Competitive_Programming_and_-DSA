#include<bits/stdc++.h> 
using namespace std; 

void DFS(vector<int> adj[], int s, bool visited[]) 
{ 
	visited[s] = true; 
    
    cout<<s<<" ";

    for(int u:adj[s]){
        if(visited[u]==false){
            DFS(adj,u, visited);
        }
    }

	
}

void DFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFS(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	DFSDin(adj,V); 

	return 0; 
} 
