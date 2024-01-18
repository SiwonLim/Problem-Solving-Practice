[Problem]<br>
https://leetcode.com/problems/maximum-depth-of-binary-tree


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
    public int maxDepth(TreeNode root) {
        return countDepth(root, 0);
    }
    public int countDepth(TreeNode node, int depth){
        int l=0,r=0;
        if(node != null){
            l = countDepth(node.left, depth+1);
            r = countDepth(node.right, depth+1);
            return Math.max(l, r);
        }
        return depth;
    }
}
```

[Answer 2]
```java
class Solution {
    public int maxDepth(TreeNode root) {
        // Base Condition
        if(root == null) return 0;
        // Hypothesis
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        // Induction
        return Math.max(left, right) + 1;
    }
}
```
