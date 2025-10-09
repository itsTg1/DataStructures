class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full=numBottles;
        int exchg=numExchange;
        int empty=full;
        full=0;
        int cnt=numBottles;
        while(empty!=0){
            if(exchg<=empty){
                full++;
                empty=empty-exchg;
                exchg++;
            }
            else{
                cnt=cnt+full;
                empty=empty+full;
                full=0;
                if(empty<exchg){
                    break;
                }
            }
        }
        cnt+=full;
        return cnt;
    }
};