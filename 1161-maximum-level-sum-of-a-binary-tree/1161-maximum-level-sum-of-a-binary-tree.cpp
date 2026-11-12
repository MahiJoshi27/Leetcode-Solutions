class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);

        int level = 0;
        int ans = 1;
        int maxSum = INT_MIN;

        while (!q.empty()) {

            level++;

            int size = q.size();
            int sum = 0;

            // Process current level
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                // Push left child
                if (node->left != NULL) {
                    q.push(node->left);
                }

                // Push right child
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // Update maximum sum
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
        }

        return ans;
    }
};