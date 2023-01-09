class Solution {
public:
    vector<int>ans;
    void preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preorderTraversal(root1);
        preorderTraversal(root2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};