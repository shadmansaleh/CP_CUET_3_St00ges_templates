const int MAXN = 200001;
const int LOG = 20;
int dp[LOG][MAXN];
int level[MAXN];
vector<int> adj[MAXN];
void dfs(int node, int par) {
    dp[0][node] = par;
    for (int i = 1; i < LOG; i++) { // Fixed boundary to LOG
        dp[i][node] = dp[i - 1][dp[i - 1][node]];
    }
    for (auto u : adj[node]) {
        if (u == par) continue;
        level[u] = level[node] + 1;
        dfs(u, node);
    }
}
adj[x].push_back(y);
adj[y].push_back(x);
level[1] = 0;
dfs(1, 0);
dp[0][1] = 0;

if (level[a] < level[b]) swap(a, b), swap(x, y);
int diff = level[a] - level[b];

for (int i = 0; i < LOG; i++) { // Fixed boundary to LOG
if (diff & (1 << i)) {
a = dp[i][a];
}
}
if (a == b) {
node = a;
} else {
for (int ii = LOG - 1; ii >= 0; ii--) { // Fixed boundary to LOG
if (dp[ii][a] != dp[ii][b]) {
a = dp[ii][a];
b = dp[ii][b];
}
}
node = dp[0][a];
}
