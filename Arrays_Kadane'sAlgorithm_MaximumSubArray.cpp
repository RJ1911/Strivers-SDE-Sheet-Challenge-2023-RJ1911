class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        

        
//Brute Force 1 ---> O(N^3)
//         int maxSum = INT_MIN;     
//         for(int start = 0 ; start < n ; start++)
//         {
//             for(int end = start ; end < n ; end++)
//             {
//                 int sum = accumulate(nums.begin()+start,nums.begin()+end+1,0);
//                 maxSum = max(maxSum,sum);
//             }
//         }
//      return maxSum;
        
// Brute Force II ---> O(N^2)        
     //    int maxSum = INT_MIN;     
     //    for(int start = 0 ; start < n ; start++)
     //    {
     //        int sum = 0;
     //        for(int end = start ; end < n ; end++)
     //        {
     //            sum += nums[end];
     //            maxSum = max(maxSum,sum);
     //        }
     //    }
     // return maxSum;
        
// Kadanes Algo
        int currSum = nums[0];
        int maxSum = nums[0];
        
        int start = 0;
        int ansStart = -1;
        int ansEnd = -1;
        
        for(int i = 1 ; i < n ;i++)
        {
            if(currSum > 0)
            {
                currSum += nums[i];
            }
            else
            {
                currSum = nums[i];
                // new subarray starts
                start = i;
            }
            
            if(currSum > maxSum)
            {
                maxSum = currSum;
                ansStart = start;
                ansEnd = i;
            }
        }
        for(int i = ansStart ; i <= ansEnd and i < n;i++)
        {
            cout<<nums[i]<<" ";
        }
      return maxSum;
        
    }
};
