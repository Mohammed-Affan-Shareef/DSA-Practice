//TC=O(n)  | SC=O(n)
class Solution {
public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int stIdx,int endIdx,int& idx,unordered_map<int,int>& mp){
    if(stIdx>endIdx)return NULL;
    int rootVal=preorder[idx];
    TreeNode* root=new TreeNode(rootVal);
       int i=mp[rootVal];
       idx++;
       root->left=buildTree(preorder,inorder,stIdx,i-1,idx,mp);
       root->right=buildTree(preorder,inorder,i+1,endIdx,idx,mp);
       return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int idx=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return buildTree(preorder,inorder,0,n-1,idx,mp);
    }
};