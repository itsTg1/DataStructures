int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int cnt=0;
        int n1=g.size();
        int n2=s.size();
        while(i<n1 && j<n2){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }
        return cnt;
    }