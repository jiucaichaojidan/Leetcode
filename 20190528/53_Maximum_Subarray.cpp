class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res = max(sum, res);
            if (sum < 0)
                sum = 0;
        }
        return res;      
        
        /****** O(N**2) ******/   
//         int res = nums[0];
    
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int sum = 0;
            
//             for (int j = i ; j < nums.size(); j++)
//             {
//                 sum += nums[j];
//                 res = max(sum, res);
//             }
//         }
        
//         return res;
    }
};