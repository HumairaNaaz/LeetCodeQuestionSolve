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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //both are empty
        if(p==NULL && q==NULL) return true;

        //one have ele another have not
        else if(p==NULL || q==NULL){
            return false;
        }

        //value are diffrent
        if(p->val != q->val){
            return false;
        }

        //check left nd right subtree
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};