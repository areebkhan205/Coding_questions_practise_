class Solution {
    const int MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> ways(n,0);
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        ways[0]=1;
        
        priority_queue<
          pair<long long,int>,
          vector<pair<long long ,int>>,
           greater<pair<long long ,int >>
        > pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            
            
            pq.pop();
            

            if(time>dist[node])continue;

            for(auto it:adj[node]){
                int newnode=it.first;
                int newtime=it.second;
                if(newtime+time<dist[newnode]){
                    dist[newnode]=newtime+time;
                    ways[newnode]=ways[node];
                    pq.push({dist[newnode],newnode});
                }
                else if(newtime+time==dist[newnode]){
                         ways[newnode] =
                        (ways[newnode] + ways[node]) % MOD;
                }
            }
        }

       
    return ways[n-1];
    }
};