

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  
  vector<pair<int, edge> > T;  
  int *parent;
  int y;  
   public:
  Graph(int y);
  void AddWeightedEdge(int x, int y, int z);
  int find_set(int i);
  void union_set(int x, int y);
  void kruskal();
  void print();
};
Graph::Graph(int y) {
  parent = new int[y];

  
  for (int i = 0; i < y; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int x, int y, int z) {
  G.push_back(make_pair(z, edge(x, y)));
}
int Graph::find_set(int i) {
  
  if (i == parent[i])
    return i;
  else

    return find_set(parent[i]);
}

void Graph::union_set(int x, int y) {
  parent[x] = parent[y];
}
void Graph::kruskal() {
  int i, xRep, yRep;
  sort(G.begin(), G.end());  
  for (i = 0; i < G.size(); i++) {
    xRep = find_set(G[i].second.first);
    yRep = find_set(G[i].second.second);
    if (xRep != yRep) {
      T.push_back(G[i]);  
      union_set(xRep, yRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWeightedEdge(0, 2, 1);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}
