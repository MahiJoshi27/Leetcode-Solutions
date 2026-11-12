class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == NULL) {
            return NULL;
        }

        // If current node is p or q
        if (root == p || root == q) {
            return root;
        }

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides return a node
        if (left != NULL && right != NULL) {
            return root;
        }

        // Otherwise return the non-NULL result
        if (left != NULL) {
            return left;
        }

        return right;
    }
};