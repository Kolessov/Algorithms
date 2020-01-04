#include <iostream>
#include <queue>
#include <vector>

using namespace std;



class Graph{
public:

	vector<vector<int>> adjacents;
	vector<int> color; // a vertex is labeled {0, 1, 2}
	vector<int> parent; // which is a vertex is  parent for current vertex (for trees)
	queue<int> BFS_queue;
	vector<int> disctances;

	Graph(int n)
	{
		color.resize(n,0);
		parent.resize(n,-1);
		adjacents.resize(n,vector<int>());
		
	}

	void Init(int m);
	void BreadFirstSearch(int vertex);
};



void  Graph::Init(int m)
{
	
	cin >> m;
	int u,v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		u --;
		v --;
		adjacents[u].push_back(move(v));
		adjacents[v].push_back(move(u));
	}
}



void Graph::BreadFirstSearch(int vertex)
{
    vector<int> distances;
    distances.resize(adjacents.size(),-1);
	int current;
	color[vertex] = 1;
	BFS_queue.push(move(vertex));
	while(!BFS_queue.empty())
		
		current = BFS_queue.front();
		BFS_queue.pop();
		for(size_t i = 0; i < adjacents[current].size(); ++ i)
		{
			if(color[adjacents[current][i]] == 0)
			{
				parent[adjacents[current][i]] = move(current);
				color[adjacents[current][i]] = 1;
				distances[adjacents[current][i]] = distances[current] + 1;
				BFS_queue.push(move(adjacents[current][i]));
			}
		}
	color[vertex] = 2;

}



int main()
{
	int n, m, first, second;
	cin >> n >> m >> first >> second;
	first--;
	second--;
	Graph graph(n);
	graph.Init(m);
	graph.BreadFirstSearch(first);
	if (graph.parent[second] == -1 && first != second) {
		cout << "-1" << endl;
	}
	else {
		vector<int> result;
		int current = second;
		while (current >= 0 && current != first) {
			result.push_back(current + 1);
			current = graph.parent[current];
		}
		cout << result.size() << endl;
		cout << first + 1 << ' ';
		for (int i = result.size() - 1; i >= 0; i--) {
			cout << result[i] << ' ';
		}
	}
	return 0;
}