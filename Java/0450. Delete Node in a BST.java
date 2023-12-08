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
    public TreeNode getBSTMin(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        
        return node;
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }

        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            //DELETE NODE WITH NO CHILD
            if (root.left == null && root.right == null) {
                return null;
            }
            
            //DELETE NODE WITH 1 CHILD
            else if (root.left == null || root.right == null) {
                TreeNode temp;

                if (root.left == null) {
                    temp = root.right;
                } else {
                    temp = root.left;
                }
                
                return temp;
            }

            //DELETE NODE WITH 2 CHILD
            else {
                TreeNode temp;
                temp = getBSTMin(root.right);
                root.val = temp.val;
                root.right = deleteNode(root.right, temp.val);
            }
        }
        
        return root;
    }
}