class Solution {
public:
    queue<vector<int>> q;
   
    vector<pair<int,int>> pos={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        for(auto it:sources){
            int x=it[0];
            int y=it[1];
            int color=it[2];
            
            grid[x][y]=color;
            time[x][y]=0;
            q.push({x,y,color,0});
        }
        while(!q.empty()){
            auto fronNode=q.front();
            q.pop();
            int x=fronNode[0];
            int y=fronNode[1];
            int clr=fronNode[2];
            int t=fronNode[3];
            for(auto it:pos){
                int newx=x+it.first;
                int newy=y+it.second;
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(time[newx][newy]>t+1){
                        time[newx][newy]=t+1;
                        grid[newx][newy]=clr;
                        q.push({newx,newy,clr,t+1});
                    }
                    else if(time[newx][newy]==t+1){
                        if(grid[newx][newy]<grid[x][y]){
                            grid[newx][newy]=grid[x][y];
                            q.push({newx,newy,grid[newx][newy],t+1});
                        }
                
                    }
                    
                }
            }
        }
        return grid;
    }
};