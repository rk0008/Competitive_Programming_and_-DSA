#include<bits/stdc++.h> 
using namespace std; 

void topologicalsort(vector<int> adj[], int V) 
{ 
     vector<int> indegree(V, 0); 
  
      for(int i=0;i<V;i++){
          for(int x:adj[i]){
              indegree[x]++;
          }
      }
      queue<int> q;
      
      for(int i=0;i<V;i++){
          if(indegree[i]==0){
              q.push(i);
          }
      }

      while(q.empty()==false){
          int x=q.front();
          q.pop();
          cout<<x<<" ";
          for(int u:adj[x]){
              if(--indegree[u]==0)
              q.push(u);
          }
      }


} 
void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}


void TopologicalSort(vector<int> adj[], int V) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
	stack<int> st;
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
   
}



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    
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
    
  

    topologicalsort(adj,V);

	

	return 0; 
} 
