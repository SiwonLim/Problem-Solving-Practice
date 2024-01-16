[Problem]<br>
https://leetcode.com/problems/binary-tree-inorder-traversal


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
    List<Integer> arr = new ArrayList<Integer>();
    public List<Integer> inorderTraversal(TreeNode root) {
        recursiveTravesal(root);
        return arr;
    }
    public void recursiveTravesal(TreeNode root){
        if(root == null){
            return;
        }
        //left root right
        recursiveTravesal(root.left);
        arr.add(root.val);
        recursiveTravesal(root.right);
    }
}
```
