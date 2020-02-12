class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> answer;
        int size = arr.size(),left = 0,right = size - 1,mid,counter = 0;
        while(right - left > 1)
        {
            mid = right/2 + left/2;
            if(arr[mid] > x){right = mid;}
            else{left = mid;}
        }
        int closest = abs(arr[left] - x) < abs(arr[right] - x) ? left : right;
        
        int i = closest;
        while(i >= 0 and counter < k)
        {
            answer.push_back(arr[i]);
            i--;
            counter++;
        }
        
        reverse(answer.begin(),answer.end());
        
        i = closest + 1;
        counter = 0;
        while(i < size and counter < k)
        {
            answer.push_back(arr[i]);
            counter++;
            i++;
        }
        
        left = 0,right = answer.size() -1;
        while(answer.size() != k)
        {
            if(abs(x - answer[right]) < abs(answer[left] - x))
            {
                answer.erase(answer.begin());
            }
            else
            {
                answer.erase(answer.end()-1);
            }
        }
            
        return answer;
    }
};
