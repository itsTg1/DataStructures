class Solution {
public:
    bool isPossible(vector<int>& arr, int start, vector<bool>& visited) {
        if (start < 0 || start >= arr.size() || visited[start])
            return false;
        if (arr[start] == 0)
            return true;

        visited[start] = true;

        return isPossible(arr, start + arr[start], visited) ||
               isPossible(arr, start - arr[start], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return isPossible(arr, start, visited);
    }
};