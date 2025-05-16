
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<pair<int,bool>> st;
        
        int i=0;
        while(i<asteroids.size()){
            bool currSign;
            if(asteroids[i]<0){
                currSign=0;
            }
            else{
                currSign=1;
            }
            while(!st.empty() && currSign==0 && st.top().second==1){
                if(abs(asteroids[i])>abs(st.top().first)){
                    st.pop();
                }
                else if(abs(asteroids[i])<abs(st.top().first)){
                    asteroids[i]=2000;
                    break;
                }
                else if(abs(asteroids[i])==abs(st.top().first)){
                    st.pop();
                    asteroids[i]=2000;
                    break;
                }
            }
            if(asteroids[i]!=2000){
                
                st.push({asteroids[i],currSign});
            }
            i++;
        }
        
        vector<int> ans;
      
        while(!st.empty()){
            
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};