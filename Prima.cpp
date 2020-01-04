 #include <iostream>
#include <queue>
#include <vector>
#include <utility>



const int INF = 10000000; 

class Graph{
public:
  std::vector<std::vector<int>> adjacents;
  std::vector<int> key;
  std::priority_queue<std::pair<int,int>> prioritet;
  std::vector<int> parent;
  std::vector<std::vector<int>> weights;

  Graph(int n)
  {
    adjacents.resize(n,std::vector<int>());
    key.resize(n,-INF);
    parent.resize(n,-1);
    weights.resize(n,std::vector<int>());

  }

  void Init(int m);
  void PrimeAlgorithm(int vertex);
};



void Graph::Init(int m)
{
  std::cin >> m;
  int u,v,w;
  for(int i = 0; i < m; ++i)
  {
    std::cin >> u >> v >> w;
    u--;
    v--;
    adjacents[u].push_back(std::move(v));
    weights[u][v] = std::move(w);
    adjacents[v].push_back(std::move(u));
    weights[v][u] = std::move(w);
  }
}

void Graph::PrimeAlgorithm(int vertex)
{
  
  bool logistic = false;
  key.resize(adjacents.size(),-1);
  parent.resize(adjacents.size(),-1);


  key[vertex] = 0;
  std::priority_queue<std::pair<int,int>> prioritet;
  for(int i = 0; i < adjacents.size() ; ++i)
  {
    prioritet.push(std::make_pair(- key[i],i));
  }
  while(!prioritet.empty())
  {
    int current = prioritet.top().second;
    prioritet.pop();
    for(int i = 0; i < adjacents[current].size(); ++i )
    {
       /// the problem with iterators in priority_queue



      if(weights[current][adjacents[current][i]] < key[adjacents[current][i]] && logistic == true)
      {
        key[adjacents[current][i]] = std::move(weights[current][adjacents[current][i]]);
        parent[adjacents[current][i]] = std::move(current);
        prioritet.push(std::make_pair(key[adjacents[current][i]], adjacents[current][i]));
      }
    }
  }
}



int main()
{
  return 0;
}


