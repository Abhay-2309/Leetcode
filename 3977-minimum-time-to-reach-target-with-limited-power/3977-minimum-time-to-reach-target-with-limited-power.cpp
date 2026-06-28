#define tt tuple<long long ,long long,long long>
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        int size = edges.size();
        if(source == target) return {0,power};
        vector<pair<int,int>>graph[n];
        for(const auto& itr: edges)graph[itr[0]].emplace_back(itr[1],itr[2]);
        priority_queue<tt> pq;
        pq.emplace(-0ll,power,source);
        vector<long long>res(n,-1);
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            long long time  = -get<0>(temp);
            long long po = get<1>(temp);
            long long u = get<2>(temp);
            if(po<=res[u]) continue;
            res[u] = po;
            if (u==target) return {time, po};
            if (po<cost[u])continue;
            for(const auto& child: graph[u]){
                long long nextw = time + child.second;
                if ((po - cost[u]) > res[child.first]){
                    pq.emplace(-nextw,po - cost[u],child.first);
                }
            }
        }
        return {-1,-1};
    }
};