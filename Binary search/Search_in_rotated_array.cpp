class Solution {
public:  
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)   return mid;
            if(nums[mid]>nums[high]){ //eg.4,5,6,7,8,1,2
                if(target>=nums[low]&&target<=nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{  //eg.5,6,0,1,2,3,4
                if(target>=nums[mid]&&target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }         
        }
        return -1;
    }
};
