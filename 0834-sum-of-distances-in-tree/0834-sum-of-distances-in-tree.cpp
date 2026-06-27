class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        vector<vector<int>>tree(n);
        for(auto itr: edges){
            tree[itr[0]].push_back(itr[1]);
            tree[itr[1]].push_back(itr[0]);
        }
        vector<int>nodecount(n);
        vector<int>visited(n);
        vector<int>distance(n);
        long long root_result = 0;
        auto DFS = [&](auto &&self,int node,int parent,int curr_depth)->long long{
            long long count = 1;
            root_result += curr_depth;
            for(auto &negh:tree[node]){
                if(negh == parent){
                    continue;
                }
                count += self(self,negh,node,curr_depth+1);
            }

            return nodecount[node] = count; 
        };
        DFS(DFS,0,-1,0);
        distance[0] = root_result;
        auto DFS2 = [&](auto&&self,int node,int parent) ->void{
            for(int &child :tree[node]){
                if(child==parent)continue;
                distance[child] = distance[node] - 2*nodecount[child] + n;
                self(self,child,node);
            }
        };
        DFS2(DFS2,0,-1);
        return distance;
    }
};