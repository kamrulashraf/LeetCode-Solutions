/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    
    public int MaxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int ret1  = 1, ret2 = 1;
        
        if(root.left != null){
            ret1 = 1 + MaxDepth(root.left);
        }
        if(root.right != null){
            ret2 = 1 + MaxDepth(root.right);
        }
        
        return Math.Max(ret1, ret2);
        
    }
}