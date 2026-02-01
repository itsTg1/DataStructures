class Solution {
public:
    
    unordered_map<string,vector<pair<string,int>>> mp;
    map<pair<string,string>,long long> costs;   // FIX: int → long long
    set<int> st;
    typedef long long ll;

    ll BIG_VALUE = 1e10;

    ll dijkstra(string &src,string &dest){        // FIX: return type int → ll
        unordered_map<string,ll> dist;          // FIX: int → ll

        priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<pair<ll,string>>> pq; // FIX
        pq.push({0,src});
        dist[dest]=BIG_VALUE;
        dist[src]=0;

        while(!pq.empty()){
            auto frontNod=pq.top();
            pq.pop();
            string node=frontNod.second;        // FIX: avoid shadowing
            ll currdist=frontNod.first;         // FIX: int → ll

            for(auto nbr:mp[node]){
                if(dist.find(nbr.first)==dist.end()){
                    dist[nbr.first]=BIG_VALUE;
                }
                if(currdist + nbr.second < dist[nbr.first]){
                    dist[nbr.first]=currdist + nbr.second;
                    pq.push({dist[nbr.first],nbr.first});
                }
            }
        }
        
        if(dist[dest]==BIG_VALUE){
            return -1;
        }
        return dist[dest];
    }

    ll findAllCosts(string &source,string &target,int i,vector<ll> &dp){
        if(i>=source.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        ll ans=BIG_VALUE;
        
        for(auto it:st){
            if(i+it>source.length()){
                break;
            }
            string temp=source.substr(i,it);
            string newTarget=target.substr(i,it);

            if(temp==newTarget){
                ans=min(ans,findAllCosts(source,target,i+it,dp));
            }

            if(mp.find(temp)!=mp.end()){
                ll costt;                       // FIX: int → ll
                if(costs.find({temp,newTarget})!=costs.end()){
                    costt=costs[{temp,newTarget}];
                } else {
                    costt=dijkstra(temp,newTarget);
                }

                if(costt!=-1){
                    costs[{temp,newTarget}]=costt;
                    ans=min(ans,costt+findAllCosts(source,target,i+it,dp));
                }
            }
        }
        return dp[i]=ans;
    }

    ll minimumCost(string source, string target,
                   vector<string>& original,
                   vector<string>& changed,
                   vector<int>& cost) {

        st.insert(1);
        vector<ll> dp(source.size(),-1);

        for(int i=0;i<original.size();i++){
            mp[original[i]].push_back({changed[i],cost[i]});
            st.insert(original[i].length());
        }

        ll ans=findAllCosts(source,target,0,dp);
        if(ans==BIG_VALUE){
            return -1;
        }
        return ans;
    }
};
