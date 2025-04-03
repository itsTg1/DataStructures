class Solution
{
    public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return find(parent[x]);
    }
    void findUnion(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=1;
	    }
	    
	    for(int u=0;u<V;u++){
	        for(auto v:adj[u]){
	            if(u<v){
	                int parent_x=find(u);
	                int parent_y=find(v);
	                if(parent_x==parent_y){
	                    return true;
	                }
	                else{
	                    findUnion(u,v);
	                }
	            }
	        }
	    }
	    return false;
	}
};