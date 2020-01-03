#include <iostream>
#include <vector>

using namespace std;


class Graph
{
public:
  vector<int> colors;
  vector<vector<int>> adjacents;
  vector<int> result;
  int is_cycle;

  Graph(int n)
  {
    colors.resize(n,0);
    adjacents.resize(n,vector<int>());
    is_cycle = false;
  }

  void Init(int m);
  void DepthFirstSearch(int vertex);
};

void Graph::Init(int m)
{
  cin >> m;
  int u,v;
  for(int i = 0; i < m; ++i)
  {
    cin >> u >> v;
    u--;
    v--;
    adjacents[u].push_back(move(v));
  }

}

void Graph::DepthFirstSearch(int vertex)
{
  colors[vertex] = 1;
  for(int i = 0; i < adjacents[vertex].size(); ++i)
    if(colors[adjacents[vertex][i]] == 0 )
    {
      DepthFirstSearch(adjacents[vertex][i]);
    }
    else if(colors[adjacents[vertex][i]] == 1)
    {
      is_cycle = true;

    }
  result.push_back(move(vertex));
  colors[vertex] = 2;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Graph graph(n);
  graph.Init(m);
  for (int i = 0; i < n; i++) {
    if (graph.colors[i] == 0) {
      graph.DepthFirstSearch(i);
    }
  }
  if (graph.is_cycle) {
    cout << "-1" << endl;
  }
  else {
    for (int i = graph.result.size() - 1; i >= 0; i--) {
      cout << graph.result[i] + 1 << ' ';
    }
  }
  return 0;
}