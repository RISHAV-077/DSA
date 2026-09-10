class Solution {
public:

    TreeNode* solve(TreeNode* root, int limit, int sum) {

        if (root == NULL)
            return NULL;

        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum < limit) {
                return NULL;
            }
            return root;
        }
        root->left = solve(root->left, limit, sum);
        root->right = solve(root->right, limit, sum);
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return solve(root, limit, 0);
    }
};