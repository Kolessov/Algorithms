#include <iostream>
#include <vector>
 
static std::vector<int> mark,left_vector,right_vector,input_array;

template<class T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& vect)
{
    for(const auto& x: vect)
    {
        os << x << " ";
    }
    return os;
}



void dfs_left_neighbor(int index)
{
    mark[index] = 1;
    left_vector.push_back(std::move(input_array[index]));
    if(2*index + 1 < input_array.size() and mark[2*index + 1] == 0)
    {
        dfs_left_neighbor(2*index + 1);
    }
    if(2*index + 2 < input_array.size() and mark[2*index + 2] == 0)
    {
        dfs_left_neighbor(2*index + 2);
    }
}

void dfs_right_neighbor(int index)
{
    mark[index] = 1;
    right_vector.push_back(std::move(input_array[index]));
    if(2*index + 2 < input_array.size() and mark[2*index + 2] == 0)
    {
        dfs_right_neighbor(2*index + 2);
    }
    if(2*index + 1 < input_array.size() and mark[2*index + 1] == 0)
    {
        dfs_right_neighbor(2*index + 1);
    }
}

int main()
{
    int n, element;
    std::cout << "input n";
    std::cin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        std::cin >> element;
        input_array.push_back(std::move(element));
    }

    mark.resize(input_array.size(),0);
    mark[0] = 1;
    
    dfs_left_neighbor(1);
    dfs_right_neighbor(2);
    
    std::cout << left_vector << std::endl;
    std::cout << right_vector << std::endl;
    std::cout << (left_vector == right_vector) ? "true" : "false" ;
    
    
    return 0;
    
}
