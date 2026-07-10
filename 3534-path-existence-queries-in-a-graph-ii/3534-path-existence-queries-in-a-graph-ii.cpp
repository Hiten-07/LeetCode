class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        const int LOG = 17;

        // Sort indices by value
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });

        // sortedPos[original node] = its position in sorted order
        vector<int> sortedPos(n);
        vector<int> sortedVal(n);
        for (int i = 0; i < n; i++) {
            sortedPos[order[i]] = i;
            sortedVal[i] = nums[order[i]];
        }

        // Binary lifting table: st[i][j] = farthest index reachable from i in 2^j hops
        vector<array<int, 17>> st(n);
        for (int i = 0; i < n; i++) st[i].fill(i); // default: stay in place

        // Two-pointer: find st[i][0] for each i
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, i);
            while (r + 1 < n && sortedVal[r + 1] - sortedVal[i] <= maxDiff)
                r++;
            st[i][0] = r;
        }

        // Fill lifting table
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                st[i][j] = st[st[i][j-1]][j-1];

        // Answer queries
        vector<int> ans;
        for (auto& q : queries) {
            int a = sortedPos[q[0]], b = sortedPos[q[1]];
            if (a > b) swap(a, b);

            if (a == b) { ans.push_back(0); continue; }

            int curr = a, steps = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if (st[curr][j] < b) {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }

            // One final hop to reach b
            if (st[curr][0] >= b)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};