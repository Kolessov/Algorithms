#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

std::ostream& operator<<(std::ostream& os,const std::vector<int>& v)
{
    for(const auto& x: v)
    {
        os << x << " ";
    }
    return os;
}

class Graph
{
public:
    std::vector<std::vector<int>> adjacents_list;
    std::vector<int> counter;
    Graph(int n);
    void Init(int m);
    std::vector<int> Count_counter(std::vector<std::vector<int>> adj);
    std::vector<int> TopologicalSort(std::vector<int> counter, std::vector<std::vector<int>> adjacents_list);
};


Graph::Graph(int n)
{
    adjacents_list.resize(n, std::vector<int>());
    counter.resize(n,0);
}


void Graph::Init(int m)
{
    int u,v;
    for(int i = 0; i < m; ++i)
    {
        std::cin >> u >> v;
        u--;
        v--;
        adjacents_list[u].push_back(std::move(v));
    }
}


std::vector<int> Graph::Count_counter(std::vector<std::vector<int>> adj)
{
    for(int i = 0; i < adj.size(); ++i)
    {
        counter[i] = std::move(adj[i].size());
    }
    return counter;
}


std::vector<int> Graph::TopologicalSort(std::vector<int> counter, std::vector<std::vector<int>> adjacents_list)
{
    std::stack<int> zeroes;
    std::vector<int> answer;
    answer.resize(counter.size(),0);
    int vertex;
    
    for(int i = 0; i < counter.size();++i)
    {
        if(counter[i] == 0)
        {
            zeroes.push(std::move(i));// add the number of vertex
        }
        
    }
    
    for(int i = 0; i < counter.size(); ++i)
    {
        vertex = std::move(zeroes.top());
        zeroes.pop();
        answer[i] = std::move(vertex);
        for(int j = 0; j < adjacents_list.size();++j)
        {
            for(int k = 0; k < adjacents_list[j].size();++k)
            {
                if(adjacents_list[j][k] == vertex)
                {
                    counter[j]--;
                    if(counter[j] == 0)
                    {
                        zeroes.push(std::move(j));
                    }
                }
            }
             
        }
        
    }
    std::reverse(answer.begin(),answer.end());
    return answer;
}



int main()
{
    int n, m;
	std::cin >> n >> m;
	Graph graph(n);
	graph.Init(m);
	std::cout << graph.adjacents_list[0] << std::endl;
	std::cout << graph.adjacents_list[1] << std::endl;
	std::cout << graph.adjacents_list[2] << std::endl;
	std::cout << graph.adjacents_list[3] << std::endl;
	graph.Count_counter(graph.adjacents_list);
	std::cout << graph.counter << std::endl;
	std::cout << graph.TopologicalSort(graph.counter,graph.adjacents_list);
	
    return 0;
}
