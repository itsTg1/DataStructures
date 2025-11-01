class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board, vector<vector<int>> &visited,int m,int n){
        if(row<0 || col<0 || row>=m || col>=n){
            return;
        }
        if(visited[row][col] || board[row][col]!='O'){
            return;
        }
        visited[row][col]=1;
        dfs(row+1,col,board,visited,m,n);
        dfs(row-1,col,board,visited,m,n);
        dfs(row,col-1,board,visited,m,n);
        dfs(row,col+1,board,visited,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        //traverese boundaries O's
        for(int i=0;i<n;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0,i,board,visited,m,n);
            }
            if(!visited[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1,i,board,visited,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,board,visited,m,n);
            }
            if(!visited[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,visited,m,n);
            }
        }
        // mark all unvisited O as X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }



    }
};