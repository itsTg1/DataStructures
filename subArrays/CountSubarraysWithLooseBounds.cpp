class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int i = 0;
        int j = 0;
        long long cnt = 0;
        while (j < nums.size()) {
            if (nums[j] >= minK && nums[j] <= maxK) {
                if (i == -1) {

                    i = j;
                }
                j++;
            } else {

                if (i != -1) {

                    int temp = (j - i);

                    cnt += (long long)((long long)((long long)(1 + temp) * (long long)temp) / 2);

                    i = -1;
                }

                j++;
            }
        }
        if (i != -1) {

            int temp = (j - i);

            cnt += (long long)((long long)((long long)(1 + temp) * (long long)temp) / 2);

            i = -1;
        }

        return cnt;
    }
};