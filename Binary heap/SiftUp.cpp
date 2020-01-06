#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 

void SiftUp(vector<int>& a,int index)
{
    while(a[index] < a[(index - 1)/2])
    {
        swap(a[index],a[(index -1)/2]);
        SiftUp(a,(index - 1)/2);
    }
}

ostream& operator<<(ostream& os,const vector<int>& a)
{
     
    for(const auto& x:a)
    {
        os << x << " ";
    }
    return os;
}

int main()
{
    vector<int> array_binary_heap = {3,5,6,6,8,9,11,1,13};
    SiftUp(array_binary_heap,7);
    
    cout << array_binary_heap;
    return 0;
}