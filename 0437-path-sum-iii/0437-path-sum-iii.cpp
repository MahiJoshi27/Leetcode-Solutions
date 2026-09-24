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

    int dfs(TreeNode* root, long long target) {
        if (root == NULL)
            return 0;

        int count = 0;

        target -= root->val;

        if (target == 0)
            count++;

        count += dfs(root->left, target);
        count += dfs(root->right, target);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        int count = 0;

        // Start path from current root
        count += dfs(root, targetSum);

        // Try every node in left subtree
        count += pathSum(root->left, targetSum);

        // Try every node in right subtree
        count += pathSum(root->right, targetSum);

        return count;
    }
};