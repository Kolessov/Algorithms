#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SiftUp(vector<int>& a, int index)
{
    while(a[index] < a[(index - 1)/2])
    {
        swap(a[index],a[(index - 1)/2]);
        SiftUp(a,(index - 1)/2);
    }
}

ostream& operator<<(ostream& os,const vector<int>& v)
{
    for(const auto& x:v)
    {
        os << x << " ";
    }
    return os;
}

vector<int> Build_binary_heap(vector<int>& a)
{
    vector<int> binary_heap;
    for(const auto element:a)
    {
        binary_heap.push_back(element);
        SiftUp(binary_heap,binary_heap.size() - 1);
    }
    
    return binary_heap;
}

int main()
{
    vector<int>  wet_array = {8,5,3,2,4,7,1};
    cout << Build_binary_heap(wet_array);
     
    return 0;
}