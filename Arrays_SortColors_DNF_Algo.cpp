class Solution {
public:
    void sortColors(vector<int>& nums) {
// Approach 1
//         int zero = 0 ;
//         int one = 0;
//         int two = 0;
        
//         for(int i = 0 ; i < nums.size();i++)
//         {
//             if(nums[i] == 0) zero++;
//             else if(nums[i] ==1) one++;
//             else two++;
//             nums[i] = 2;
//         }
        
//         for(int i = 0;i < zero ;i++)
//         {
//             nums[i] = 0;
//         }
//         for(int i = zero ; i < zero+one;i++)
//         {
//             nums[i] = 1;
//         }

      //Approach 2 DNF algorithm 
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
