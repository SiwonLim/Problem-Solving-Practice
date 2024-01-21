[Problem]<br>
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

[Answer 1]
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return createBTS(nums, 0, nums.length-1);
    }

    public TreeNode createBTS(int nums[], int l, int r){
        if(l > r){
            return null;
        }
        int mid = l + (r - l) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = createBTS(nums, l, mid-1);
        root.right = createBTS(nums, mid+1, r);
        return root;
    }
}
```
