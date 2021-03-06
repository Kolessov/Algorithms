#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SiftUp(vector<int>& a,int index)
{
    while(a[index] < a[(index - 1)/2])
    {
        swap(a[index],a[(index - 1)/2]);
        SiftUp(a,(index - 1)/2);
    }

}

void SiftDown(vector<int>& a, int index)
{
    while(2*index + 1 < a.size())
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int j = left;
        if(2*index + 2 < a.size() && a[right] < a[left])
        {
            j = right;
        }
        if(a[index] < a[j] )
        {
            break;
        }
        swap(a[index],a[j]);
        SiftDown(a,j);
    }
}

int ExtractMin(vector<int>& a)
{
    int min = a[0];
    a[0] = a[a.size() - 1];
    a.erase(a.begin() + a.size() - 1);
    SiftDown(a,0);
    return min;
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
    vector<int> array_binary_heap = {3,4,6,6,8,9,11,12,13};
    ExtractMin(array_binary_heap);
    cout << array_binary_heap;
    return 0;
}