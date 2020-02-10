#include <iostream>
#include <vector>

class Graph
{
public:
	std::vector<int> colors;
	std::vector<std::vector<int>> adjacents;
	std::vector<int> result;
	bool is_cycle;

	Graph(int n)
	{
		colors.resize(n,0);
		adjacents.resize(n,std::vector<int>());
		result.resize(n,-1);
		is_cycle = false;
	}

	void Init(int m);
	void DFS(int vertex);
};


void Graph::Init(int m)
{
	int u,v;
	for(int i = 0; i < m ; ++i )
	{
		std::cin >> u >> v;
		u--;
		v--;
		adjacents[u].push_back(std::move(v));
	}
}


void Graph::DFS(int vertex)
{
	colors[vertex] = 1;
	for(int i = 0; i < adjacents[vertex].size(); ++i)
	{
		if(colors[adjacents[vertex][i]] == 0)
		{
			DFS(adjacents[vertex][i]);
		}
		else if(colors[adjacents[vertex][i]] == 1)
		{
			is_cycle = true;
			break;
		}
	}
	result.push_back(std::move(vertex));
	colors[vertex] = 2;
}


int main()
{
	int n, m;
	std::cin >> n >> m;
	Graph graph(n);
	graph.Init(m);
	for (int i = 0; i < n; i++) {
		if (graph.colors[i] == 0) {
			graph.DFS(i);
		}
	}
	if (graph.is_cycle) {
		std::cout << "-1" << std::endl;
	}
	else {
		for (int i = graph.result.size() - 1; i >= 0; i--) {
			std::cout << graph.result[i] + 1 << ' ';
		}
	}
	return 0;
}
