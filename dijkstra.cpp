#include <iostream>
#include <vector>
#include<queue>
#include <functional>
using namespace std;

const int INF = 2009000999;

class Graph {
private:
	struct Edge {
		int to, weight;
		Edge(int v, int w) : to(v), weight(w) {}
	};
	vector<vector<Edge>> adjacency;
	vector<int> distance;
	vector<bool> used;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_queue;

	void Dijkstra(int start);
public:
	Graph(int n);
	void add_edge(int v, int u, int weight);
	vector<int>& min_distances(int start);
};

int main() {
	int num;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n, m;
		cin >> n >> m;
		Graph graph(n);
		for (int j = 0; j < m; j++) {
			int v, u, weight;
			cin >> v >> u >> weight;
			graph.add_edge(v, u, weight);
		}
		int start;
		cin >> start;
		vector<int> result = graph.min_distances(start);
		for (int j = 0; j < n; j++) {
			cout << result[j] << ' ';
		}
		cout << "\n";
	}
	return 0;
}

Graph::Graph(int n) {
	adjacency.assign(n, vector<Edge>());
	distance.assign(n, INF);
	used.assign(n, false);
}

void Graph::add_edge(int v, int u, int weight) {
	adjacency[v].push_back(Edge(u, weight));
	adjacency[u].push_back(Edge(v, weight));
}

void Graph::Dijkstra(int start) {
	while (!dijkstra_queue.empty()) {
		dijkstra_queue.pop();
	}
	distance[start] = 0;
	dijkstra_queue.push(make_pair(0, start));
	for (int i = 0; !dijkstra_queue.empty() && i < distance.size(); i++) {
		int min_vertex = dijkstra_queue.top().second;
		dijkstra_queue.pop();
		while (used[min_vertex]) {
			min_vertex = dijkstra_queue.top().second;
			dijkstra_queue.pop();
		}
		used[min_vertex] = true;
		for (auto edge : adjacency[min_vertex]) {
			if (!used[edge.to] && distance[edge.to] > distance[min_vertex] + edge.weight) {
				distance[edge.to] = distance[min_vertex] + edge.weight;
				dijkstra_queue.push(make_pair(distance[edge.to], edge.to));
			}
		}
	}
}

vector<int>& Graph::min_distances(int start) {
	Dijkstra(start);
	return distance;
}
