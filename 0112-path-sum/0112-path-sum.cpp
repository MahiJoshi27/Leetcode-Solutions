class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Base case
        if (root == NULL) {
            return false;
        }

        // Subtract current node value
        targetSum = targetSum - root->val;

        // Check if current node is leaf
        if (root->left == NULL && root->right == NULL) {
            return targetSum == 0;
        }

        // Check left and right subtree
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};