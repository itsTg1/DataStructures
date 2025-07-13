class Solution {
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        long long n = arr.size();
        
        d = d % n;
        
        vector<int> temp(n);
        
        // Copying elements into the new temp array in the rotated order.
        for(int i = 0; i < n; i++) {
            temp[i] = arr[(i + d) % n];
        }
        
        // Copying the temp array back to the original array.
        arr = temp;
    }
};


// Modular Operation: d = d % n ensures that if d is larger than the array size, the rotation wraps 
// around properly (e.g., rotating by 7 in an array of size 5 is equivalent to rotating by 2).