class Solution {
  public:
    map<int,vector<int>> adjList;
    map<int,int> indegree;
    map<int,bool> isVisited;
    void findTopSort(int V,vector<int> &ans){
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree.find(i)==indegree.end()){
                q.push(i);
                isVisited[i]=true;
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0 && !isVisited[nbr]){
                    q.push(nbr);
                    isVisited[nbr]=1;
                }
            }
        }
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
        }
        for(auto it:adjList){
            for(auto i : it.second){
                indegree[i]++;
            }
        }
        findTopSort(V,ans);
        return ans;
        
    }
};