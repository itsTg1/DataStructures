class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long ms=(long long)mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=ms){
                ms+=(long long)asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};