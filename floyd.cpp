#include <iostream>
#include <vector>

using namespace std;

const int INF = 2000000;

class Graph
{
public:
    Graph(int n);
    void add_edge(int u,int v, int weight);
    int min_distance(int start,int finish);
    
private:
    vector<vector<int>> floyd_matrix;
    void floyd();
};

Graph::Graph(int n)
{
    floyd_matrix.assign(n,vector<int>(n));
}

void Graph::add_edge(int u,int v,int weight)
{
    floyd_matrix[u][v] = (weight == -1) ?  INF : weight;
}

void Graph::floyd()
{
    for(int k = 0; k < floyd_matrix.size();++k)
    {
        for(int i = 0; i < floyd_matrix.size();++i)
        {
            for(int j = 0;j < floyd_matrix.size();++j)
            {
                if(floyd_matrix[i][j] > floyd_matrix[i][k] + floyd_matrix[k][j])
                {
                    floyd_matrix[i][j] = floyd_matrix[i][k] + floyd_matrix[k][j];
                }
            }
        }
    }
}

int Graph::min_distance(int start, int finish)
{
    floyd();
    if(floyd_matrix[start - 1][finish - 1] == INF)
    {
        return -1;
    }
    return floyd_matrix[start - 1][finish - 1];
}

    

int main()
{
    int n, start, finish;
	cin >> n >> start >> finish;
	Graph graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int weight;
			cin >> weight;
			graph.add_edge(i, j, weight);
		}
	}
	cout << graph.min_distance(start, finish) << "\n";
    return 0;
}