class Solution {
public:
    bool checkPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int countNumbers(int n) {
        int ans = 0;
        vector<int> primes;
        
        // Generate all primes up to n
        for (int i = 2; i <= n; i++) {
            if (checkPrime(i)) {
                primes.push_back(i);
            }
        }

        // Count numbers of the form p^8
        for (int p : primes) {
            long long val = 1;
            for (int i = 0; i < 8; i++) {
                val *= p;
                if (val > n) break;
            }
            if (val <= n) ans++;
        }

        // Count numbers of the form p^2 * q^2
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n) ans++;
            }
        }

        return ans;
    }
};