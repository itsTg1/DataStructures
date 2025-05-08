class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            
            vector<pair<int,int>> directions={{0,1},{0,-1},{-1,0},{1,0}};
            typedef pair<int,vector<int>> p;
            int n=moveTime.size();
            int m=moveTime[0].size();
            vector<vector<int>> result(n,vector<int>(m,INT_MAX));
            priority_queue<p,vector<p>,greater<p>> pq;
            pq.push({0,{0,0,1}});
            while(!pq.empty()){
                p front=pq.top();
                pq.pop();
                int currTime=front.first;
                auto cordinates=front.second;
                int i=cordinates[0];
                int j=cordinates[1];
                if(i==n-1 && j==m-1){
                    return currTime;
                }
                for(auto it:directions){
                    int newi=i+it.first;
                    int newj=j+it.second;
                    
                    if(newi>=0 && newj>=0 && newi<n && newj<m ){
                        int time=0;
                        if(currTime<moveTime[newi][newj]){
                            time=moveTime[newi][newj]-currTime;
                        }
                        int step=cordinates[2];
                        int curr=time+currTime+step;
                        
                        if(curr < result[newi][newj]){
                            result[newi][newj]=curr;
                            int newstep=(step==1)?2:1;
                            pq.push({curr,{newi,newj,newstep}});
                            
                        }
                    }
                }
            }
            return false;
        }
    };