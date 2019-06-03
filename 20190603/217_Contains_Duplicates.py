class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        # version2
        return len(nums) > len(set(nums))

        # version1
        # my_set = set();
        # for i in nums:
        #     if i in my_set:
        #         return True
        #     else:
        #         my_set.add(i)
        # return False
        