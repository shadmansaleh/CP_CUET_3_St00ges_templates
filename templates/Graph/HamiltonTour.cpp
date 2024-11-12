//visits each node exactly once
int n,m;
vector<int>adj[2000];
int dp[22][1<<22];
int dfs(int node,int mask){

    if(mask==(1<<(n))-1) return 1;
    else if(node==n-1) return 0;

    if(~dp[node][mask]) return dp[node][mask];

    int ans=0;
    for(auto u:adj[node]){
        if(mask&(1<<u)) continue;
        ans+=dfs(u,mask|(1<<u));
        ans%=mod;
    }

    return dp[node][mask]=ans;

}
