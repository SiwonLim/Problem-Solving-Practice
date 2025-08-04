from typing import List
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
    
    def canJump(self, nums: List[int]) -> bool:
        maxJump=0
        for i in range(len(nums)):
            if i > maxJump:
                return False
            maxJump = max(maxJump, i+nums[i])
        return True

    def jump(self, nums: List[int]) -> int:
        jumps=0
        current_end=0
        farthest=0
        for i in range(len(nums)-1):
            farthest = max(farthest, i+nums[i])
            if i == current_end:
                jumps+=1
                current_end = farthest

        return jumps

sol = Solution();
result = sol.canJump([3,2,1,0,4])
print(result)