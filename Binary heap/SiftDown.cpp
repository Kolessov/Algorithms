 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SiftDown(vector<int>& a,int index)
{
    while (2*index + 1 < a.size())
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int j = left;
        if(2*index + 2 < a.size() && a[left] > a[right])
        {
            j = right;
        }
        if(a[index] < a[j])
        {
            break;
        }
        swap(a[index],a[j]);
        SiftDown(a,j);
        
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
    vector<int> array_binary_heap = {3,15,6,6,8,9,11,12,13};
    SiftDown(array_binary_heap,1);
    cout << array_binary_heap;
    return 0;
}