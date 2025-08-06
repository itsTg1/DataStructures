class Solution {
public:
    int findPivot(vector<int>& nums, int s, int e) {
        int pivot = nums[s];
        int l = s;
        int h = e;
        while (l < h) {
            while (l <= e && nums[l] <= pivot) {
                l++;
            }
            while (h >= s && nums[h] > pivot) {
                h--;
            }
            if (l < h) {
                swap(nums[l], nums[h]);
            }
        }
        if (l > h) {
            swap(nums[s], nums[h]);
        }
        return h;
    }
    void quickSort(vector<int>& nums, int s, int e) {
        if (s < e) {
            int pivtIdx = findPivot(nums, s, e);
            quickSort(nums, s, pivtIdx - 1);
            quickSort(nums, pivtIdx + 1, e);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        quickSort(nums, 0, e);
        return nums;
    }
};