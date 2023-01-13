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
    public bool IsSymmetric(TreeNode root) {
        return isSubTreeValid(root.left, root.right);
    }
    
    public bool isSubTreeValid(TreeNode a, TreeNode b){
        if(a == null && b == null){
            return true;
        }
        
        if((a == null && b != null) || (a != null && b == null)){
            return false;
        }
        if(a.val != b.val){
            return false;
        }
        
        return isSubTreeValid(a.left, b.right) && isSubTreeValid(a.right , b.left);
    }
}