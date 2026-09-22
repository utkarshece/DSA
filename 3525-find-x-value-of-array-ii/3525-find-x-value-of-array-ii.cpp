class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    int n;
    vector<Node> tree;

    Node merge(Node left, Node right) {
        Node res;

        // Whole segment ka product
        res.prod = (left.prod * right.prod) % k;

        // Left ke prefixes
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Right ke prefixes + poora left
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.prod * r) % k;
            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            int rem = value % k;

            tree[node] = Node();

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside range
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Only left
        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        // Only right
        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Both sides
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums,
                            int K,
                            vector<vector<int>>& queries) {

        k = K;
        n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node result = query(1, 0, n - 1,
                                start, n - 1);

            ans.push_back(result.cnt[x]);
        }

        return ans;
    }
};