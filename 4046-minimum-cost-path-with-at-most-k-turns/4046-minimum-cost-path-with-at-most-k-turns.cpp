class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1&&n==1) return grid[0][0];
        auto velmoriqan = grid;
        vector<array<int,2>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    4, vector<int>(k + 1, 1e9)
                )
            )
        );
        priority_queue<tuple<int,int,int,int,int>,vector<tuple<int,int,int,int,int>>,greater<tuple<int,int,int,int,int>>> pq;
        int d=0;
        for(auto itr: dir){
            int nr = 0+itr[0];
            int nc = 0+itr[1];
            if(nr>=0&&nr<m&&nc>=0&&nc<n){
                int intialcost = velmoriqan[0][0]+velmoriqan[nr][nc];
                dist[nr][nc][d][0]=intialcost;
                pq.emplace(intialcost,nr,nc,d,0);
            }
            d++;
        }
        while(!pq.empty()){
            auto [c,r,c_idx,cd,t] = pq.top();
            pq.pop();
            if(r==m-1&&c_idx==n-1) return c;
            if(c>dist[r][c_idx][cd][t]) continue;
            for(int nd=0;nd<4;nd++){
                int nr = r+dir[nd][0];
                int nc = c_idx+dir[nd][1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n){
                    int nt = t+(cd!=nd?1:0);
                    if(nt<=k){
                        int ncst = c+velmoriqan[nr][nc];
                        if(ncst<dist[nr][nc][nd][nt]){
                            dist[nr][nc][nd][nt]=ncst;
                            pq.emplace(ncst,nr,nc,nd,nt);
                        }
                    }
                }
            }
        }
        return -1;
    }
};