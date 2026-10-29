class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, tin, tout;
    vector<int> prefix;
    int timer = 0;
    int LOG;

    // Fenwick Tree for XOR range updates and point queries
    vector<int> bit;

    void add(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void rangeUpdate(int l, int r, int val) {
        add(l + 1, val);
        add(r + 2, val);
    }

    int pointQuery(int idx) {
        int ans = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) {
            ans ^= bit[i];
        }
        return ans;
    }

    // Iterative DFS to avoid deep recursion
    void dfs(int root) {
        vector<array<int, 3>> st;
        st.push_back({root, root, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = timer++;

                up[0][u] = p;
                prefix[u] = (u == root)
                    ? (1 << (sChar[u] - 'a'))
                    : (prefix[p] ^ (1 << (sChar[u] - 'a')));

                st.push_back({u, p, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer - 1;
            }
        }
    }

    string sChar;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        sChar = s;
        adj.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        prefix.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 2, 0);

        dfs(0);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = 1 << (sChar[u] - 'a');
                int newMask = 1 << (c - 'a');
                int change = oldMask ^ newMask;

                if (change != 0) {
                    rangeUpdate(tin[u], tout[u], change);
                    sChar[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int maskU = prefix[u] ^ pointQuery(tin[u]);
                int maskV = prefix[v] ^ pointQuery(tin[v]);
                int pathMask = maskU ^ maskV
                             ^ (1 << (sChar[w] - 'a'));

                // At most one character may have odd frequency
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};