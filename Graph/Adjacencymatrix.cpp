#include <iostream>
using namespace std;

class Graph {
  private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
 Graph(int numVertices){
     this->numVertices=numVertices;
     adjMatrix= new bool*[numVertices];
     for(int i=0;i<numVertices;i++){
        adjMatrix[i] = new bool[numVertices];
         for(int j=0;j<numVertices;j++){
        adjMatrix[i][j] = false;
         }
     }

 
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
};


// class graph{
//   private:
//   bool** adjmatrix;
//   int numvertices;
  
//   public:
//   graph(int numvertices){
//     this->numvertices=numvertices;
//     adjmatrix= new bool*[numvertices];
//     for(int i=0;i<numvertices;i++){
//       adjmatrix[i]=new bool[numvertices];
//       for(int j=0;j<numvertices;j++){
//         adjmatrix[i][j]=false;
//       }
//     }


  





int main() {
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.toString();
}