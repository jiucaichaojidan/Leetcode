class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mymap;
        for(auto num : nums1) mymap[num] += 1;
        for(auto num : nums2)
        {
            mymap[num] --;
            if (mymap[num] >= 0)
                res.push_back(num);               
                
        }
        return res;
    }
};