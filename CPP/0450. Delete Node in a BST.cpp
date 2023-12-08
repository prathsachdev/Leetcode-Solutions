/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getBSTMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            //DELETE NODE WITH NO CHILD
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            
            //DELETE NODE WITH 1 CHILD
            else if (root->left == nullptr || root->right == nullptr) {
                TreeNode* temp;

                if (root->left == nullptr) {
                    temp = root->right;
                } else {
                    temp = root->left;
                }

                return temp;
            }

            //DELETE NODE WITH 2 CHILD
            else {
                TreeNode* temp;
                temp = getBSTMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        
        return root;
    }
};