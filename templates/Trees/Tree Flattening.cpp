void dfs(int node,int par){

    timer++;
    fa[timer]=node;
    for(auto u:adj[node]){
        if(u==par) continue;
        dfs(u,node);

    }
    timer++;
    fa[timer]=node;

}
