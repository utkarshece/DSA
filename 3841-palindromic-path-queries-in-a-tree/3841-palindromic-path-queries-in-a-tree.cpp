class BinaryIndexedTree {
    int n;
    vector<int> tree;

public:
    BinaryIndexedTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int val) {
        for (++i; i <= n; i += i & -i)
            tree[i] ^= val;
    }

    int query(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i)
            ans ^= tree[i];
        return ans;
    }
};

class Solution {
    vector<vector<int>> adj, up;
    vector<int> parent, depth, tin, tout, bit;
    int timer, LOG;

    void dfs(int u, int p) {
        parent[u] = (p == -1 ? 0 : p);
        tin[u] = timer++;

        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int d = depth[u] - depth[v];

        for (int j = 0; d; j++, d >>= 1) {
            if (d & 1)
                u = up[j][u];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.resize(n);
        depth.assign(n, 0);
        tin.resize(n);
        tout.resize(n);
        timer = 0;

        dfs(0, -1);

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n));
        up[0] = parent;

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        bit.resize(n);
        for (int i = 0; i < n; i++)
            bit[i] = 1 << (s[i] - 'a');

        BinaryIndexedTree fenwick(n);

        for (int i = 0; i < n; i++) {
            fenwick.update(tin[i], bit[i]);
            fenwick.update(tout[i], bit[i]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u;
            ss >> op >> u;

            if (op == "update") {
                string c;
                ss >> c;

                int newBit = 1 << (c[0] - 'a');

                if (bit[u] != newBit) {
                    int change = bit[u] ^ newBit;

                    fenwick.update(tin[u], change);
                    fenwick.update(tout[u], change);

                    bit[u] = newBit;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = fenwick.query(tin[u] + 1)
                         ^ fenwick.query(tin[v] + 1)
                         ^ bit[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};