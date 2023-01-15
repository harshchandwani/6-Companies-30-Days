
class Solution {
public:
    int count = 0;
    pair <int,int> helper(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        auto l = helper(root->left);
        auto r = helper(root->right);
        auto sum = (l.first + r.first + root->val);
        auto size = (l.second + r.second + 1);

        if(sum/ size == root->val){
            count++;
        }
        return {sum, size};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};
