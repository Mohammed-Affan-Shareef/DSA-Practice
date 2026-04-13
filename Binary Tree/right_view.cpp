//! Using BFS(level order traversal)
//* TC=O(n)|SC=O(n);
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int size=q.size();
            TreeNode* temp;
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                temp=curr;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};
//! Using DFS
//* TC=O(n)|SC=O(n)
class Solution {
public:
void dfs(TreeNode* root,vector<int>& ans,int level){
    if(level>ans.size())ans.push_back(root->val);
    if(root->right)dfs(root->right,ans,level+1);
    if(root->left)dfs(root->left,ans,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        dfs(root,ans,1);
        return ans;
    }
};