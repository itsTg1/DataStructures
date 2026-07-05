class Solution {
public:
    int result=INT_MAX;
    void bfs(int source,unordered_map<int,bool> visited,unordered_map<int,vector<pair<int,int>>> &adj){
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int parent=q.front();
            q.pop();
            visited[parent]=1;
            for(auto nbr:adj[parent]){
                if(!visited[nbr.first]){
                    result=min(result,nbr.second);
                    q.push(nbr.first);
                }
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        unordered_map<int,bool> visited;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        bfs(1,visited,adj);
        return result;
        
    }
};