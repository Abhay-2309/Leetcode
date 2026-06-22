#define tt tuple<int,int,int>
class Solution {
public:
    const int INF = 1e9;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto const&itr: edges){
            graph[itr[0]].emplace_back(itr[1],itr[2]);
        }
        priority_queue<tt,vector<tt>,greater<tt>> pq;
        vector<vector<int>>dist(n,vector<int>(k+1,INF));
        pq.emplace(0,0,1);
        dist[0][1] = 0;
        while(!pq.empty()){
            auto [curr_dist, u,curr_consecutive] = pq.top();
            pq.pop();
            if(curr_dist>dist[u][curr_consecutive]) continue;
            if(u==n-1) return curr_dist;
            for(const auto& neghbour: graph[u]){
                int v = neghbour.first;
                int weight = neghbour.second;
                int next_consecutive = (labels[u]==labels[v])? curr_consecutive+1:1;
                if(next_consecutive>k) continue;
                if(curr_dist+weight<dist[v][next_consecutive]){
                    dist[v][next_consecutive] = curr_dist+weight;
                    pq.emplace(dist[v][next_consecutive],v,next_consecutive);
                }
            }
        }
        return -1;
    }
};
