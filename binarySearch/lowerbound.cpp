class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int lb = arr.size();  // default to arr.size() if no element ≥ target
        int s = 0, e = arr.size() - 1;

        while (s <= e) {
            int mid = (s + e) / 2;

            if (arr[mid] >= target) {
                lb = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return lb;  // may return arr.size() if no element ≥ target
    }
};