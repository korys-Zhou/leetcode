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

//=================================dfs=================================//
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return add(root, val, depth, true);
    }

    TreeNode* add(TreeNode* root, int val, int depth, bool left) {
        if (depth == 1) {
            if (left) {
                TreeNode* p = new TreeNode(val, root, nullptr);
                return p;
            }
            else {
                TreeNode* p = new TreeNode(val, nullptr, root);
                return p;
            }
        }
        if (!root) return nullptr;
        root->left = add(root->left, val, depth - 1, true);
        root->right = add(root->right, val, depth - 1, false);
        return root;
    }
};

//=================================bfs=================================//
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dum = new TreeNode(0, root, nullptr);
        int level = 0;
        queue<TreeNode*> que;
        que.emplace(dum);
        while (!que.empty()) {
            if (++level == depth) {
                while (!que.empty()) {
                    TreeNode* cur = que.front(); que.pop();
                    cur->left = new TreeNode(val, cur->left, nullptr);
                    cur->right = new TreeNode(val, nullptr, cur->right);
                }
            }
            else {
                for (int len = que.size(); len > 0; --len) {
                    TreeNode* cur = que.front(); que.pop();
                    if (cur->left) que.emplace(cur->left);
                    if (cur->right) que.emplace(cur->right);
                }
            }
        }
        TreeNode* res = dum->left;
        if (dum->right) delete dum->right;
        delete dum;
        return res;
    }
};