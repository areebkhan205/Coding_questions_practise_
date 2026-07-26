class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int src, vector<vector<pair<int,int>>> &adj, int n) {
        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (wt > dist[node]) continue;

            for (auto [next, w] : adj[node]) {
                if (dist[node] + w < dist[next]) {
                    dist[next] = dist[node] + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {

        vector<vector<pair<int,int>>> adj(n), revAdj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            revAdj[v].push_back({u, w});   // reverse edge
        }

        vector<long long> d1 = dijkstra(src1, adj, n);
        vector<long long> d2 = dijkstra(src2, adj, n);
        vector<long long> d3 = dijkstra(dest, revAdj, n);

        long long ans = INF;

        for (int i = 0; i < n; i++) {
            if (d1[i] == INF || d2[i] == INF || d3[i] == INF)
                continue;

            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        return ans == INF ? -1 : ans;
    }
};