'''
[Problem]
https://leetcode.com/problems/remove-duplicates-from-sorted-array
'''

from typing import List 
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        res = list(dict.fromkeys(nums))
        nums.clear()
        nums.extend(res)
        return len(nums)

def main():
    nums = [0,0,1,1,1,2,2,3,3,4]
    Solution.removeDuplicates(Solution,nums)

if __name__ == "__main__":
    main()