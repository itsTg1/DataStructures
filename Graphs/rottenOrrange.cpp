// Multiple bfs

class Solution {
public:
     typedef pair<int,int> p;
    vector<p> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<p> q;
        int freshOrange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
        if(freshOrange==0){
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int N=q.size();
            
            while(N--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto it:directions){
                    int _i=it.first+i;
                    int _j=it.second+j;
                    if(_i>=0 && _j>=0 && _i<m && _j<n && grid[_i][_j]==1){
                        grid[_i][_j]=2;
                        q.push({_i,_j});
                        freshOrange--;
                    }
                }
            }
            ans++;
        }
        if(freshOrange==0){
            return ans-1;
        }
        return -1;
    }
};