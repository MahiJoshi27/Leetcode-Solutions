class Solution {
public:

    void solve(TreeNode* root, vector<int>& ans) {

        // Base case
        if (root == NULL) {
            return;
        }

        // Check leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
            return;
        }

        // DFS traversal
        solve(root->left, ans);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> v1;
        vector<int> v2;

        solve(root1, v1);
        solve(root2, v2);

        return v1 == v2;
    }
};