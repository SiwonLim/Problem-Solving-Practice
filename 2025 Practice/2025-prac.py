class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = 1
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                count = 1

            if count <= 2:
                nums[temp] = nums[i]
                temp += 1
        return temp
        
sol = Solution()
result = sol.removeDuplicates([1,1,1,1,1,2,2,3])
print(result)