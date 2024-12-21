'''
[Problem]
https://leetcode.com/problems/merge-sorted-array
'''

from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i=0
        j=0
        res = []
        while(i < m and j < n):
            if nums1[i] <= nums2[j]:
                res.append(nums1[i])
                i+=1
            else:
                res.append(nums2[j])
                j+=1
        res.extend(nums1[i:m])
        res.extend(nums2[j:n])
        nums1[:m+n] = res
def main():
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    Solution.merge(Solution,nums1,m,nums2,n)
    
if __name__ == '__main__':
    main()