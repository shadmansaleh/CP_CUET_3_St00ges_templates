const int INF=1e18;
int n;
vector<vector<int>> capacity(1001,vector<int>(1001,0));
vector<vector<int>> adj(1001);
vector<vector<int>> adj3(1001);
int adj2[501][501];
int vis[10001];
int vis2[1001];
vector<pair<int,int>>ans;
void dfs(int node){

    vis[node]=1;
    for(auto u:adj[node]){
        if(vis[u] or capacity[node][u]<=0) continue;
        dfs(u);
    }
}
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



void do_the_honour(){

    int m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,w=1; cin >> x >> y ;
        capacity[x][y]+=w;
        capacity[y][x]+=w;
        adj[x].push_back(y);
        adj[y].push_back(x);
        adj2[x][y]=1;
        adj2[y][x]=1;


        adj3[x].push_back(y);
    }




    cout << maxflow(1,n) << endl;
    dfs(1);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(adj2[i][j] and vis[i] and !vis[j]) ans.push_back({i,j});

    //cout << ans.size() << endl;
    for(auto u:ans) cout << u.first << " " << u.second << endl;

```

finding max flow and cut edges for undirected graph
