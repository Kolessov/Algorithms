class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        long int left = 0;
        long int right = round(x/2) + 1;
        long int middle;
        
        
        while (left < right){
            middle = left + floor((right - left)/2);
            if(middle*middle == x){
                return middle;
            }
            if(middle*middle < x){
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return int(left - 1);
    }
};