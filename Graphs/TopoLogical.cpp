
class Solution {
  public:
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,int> indegree;
    queue<int> q;
    void findTopologicalOrder(vector<int> &ans){
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        for(auto it:edges){
            adjList[it[0]].push_back(it[1]);
        }
        
        for(auto it:adjList){
            for(auto i:it.second){
                indegree[i]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree.find(i)==indegree.end()){
                q.push(i);
            }
        }
        findTopologicalOrder(ans);
        return ans;
    }
};