class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        vector<int>ans(n,1);
        auto f = [&](auto&& self,int curr_node,int parent_node)->vector<int>{
            vector<int>parent_ans(26);
            if(!graph[curr_node].size()){
                parent_ans[labels[curr_node]-'a']=1;
                return parent_ans;
            }
            for(auto child: graph[curr_node]){
                if(child==parent_node) continue;
                auto childans = self(self,child,curr_node);
                for(int i=0;i<26;i++) parent_ans[i] += childans[i];
            }
            parent_ans[labels[curr_node]-'a'] ++;
            ans[curr_node] = parent_ans[labels[curr_node]-'a'];
            return parent_ans;
        };
        f(f,0,-1);
        return ans;
    }
};