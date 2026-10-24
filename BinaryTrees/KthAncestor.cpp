class TreeAncestor {
public:
    vector<vector<int>> ancestors;

    TreeAncestor(int n, vector<int>& parent) {
        int lvls = log2(n) + 1;

        // Initialize everything to -1
        this->ancestors = vector<vector<int>>(n, vector<int>(lvls, -1));

        // 2^0-th ancestor = immediate parent
        for (int i = 0; i < n; i++) {
            this->ancestors[i][0] = parent[i];
        }

        // Binary lifting table
        for (int j = 1; j < lvls; j++) {
            for (int i = 0; i < n; i++) {

                int mid = this->ancestors[i][j - 1];

                if (mid != -1) {
                    this->ancestors[i][j] =
                        this->ancestors[mid][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int i = 0; i < ancestors[0].size(); i++) {

            // Check i-th bit of k
            if ((k >> i) & 1) {

                if (node == -1)
                    return -1;

                node = ancestors[node][i];
            }
        }

        return node;
    }
};