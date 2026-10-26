class Solution {
public:
    void bfs(vector<vector<int>> &vis,vector<vector<int>>& grid, int k,vector<long long> &isl,int start,int end)
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.emplace(start,end);
        vis[start][end]=1;
        long long sum = grid[start][end];
        vector<int> delr={-1,0,0,1};
        vector<int> delc={0,-1,1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 && nrow<m &&ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    sum+=grid[nrow][ncol];
                    vis[nrow][ncol]=1;
                }
            }
        }
        isl.push_back(sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        vector<long long> isl;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(!vis[i][j]&&grid[i][j]){
                    bfs(vis,grid,k,isl,i,j);
                }
            }
        }
        for(auto itr:isl) cout<<itr<<" ";
        int count =0;
        for(auto itr:isl){
            if(itr%k==0) count++;
        }
        return count;
        
    }
};