class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);      
        
    }
    
    void reverse(vector<int>& nums, int start, int end)
    {
        int tmp = 0;
        while(start < end)
        {
            tmp = nums[start];
            nums[start] =  nums[end];
            nums[end] = tmp;
            start ++;
            end --;
        }
    }
    //  mine
    //  int tmp = 0;
    //     int l = nums.size() - k % nums.size();
    //     for (int i = 0; i < l; i++)
    //     {
    //         tmp = nums[0];
    //         nums.erase(nums.begin());
    //         nums.push_back(tmp);
    //     }
    
    
};