class Solution {
public:
void dfs(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<bool>>& vis){
    if(i<0||i>=heights.size()||j<0||j>=heights[0].size())return;
    if(vis[i][j]||heights[i][j]<prev)return;
    vis[i][j]=true;
    dfs(heights,i+1,j,heights[i][j],vis);
    dfs(heights,i-1,j,heights[i][j],vis);
    dfs(heights,i,j+1,heights[i][j],vis);
    dfs(heights,i,j-1,heights[i][j],vis);

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacificVisited(m,vector<bool>(n,false));
        vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));
        for(int j=0;j<n;j++){
            dfs(heights,0,j,INT_MIN,pacificVisited);
            dfs(heights,m-1,j,INT_MIN,atlanticVisited);
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,0,INT_MIN,pacificVisited);
            dfs(heights,i,n-1,INT_MIN,atlanticVisited);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVisited[i][j]&&atlanticVisited[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};