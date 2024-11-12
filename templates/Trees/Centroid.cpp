int sz;
void dfs(int node, int par){

    subtree[node]=1;
    sz++;
    for(auto u:adj[node]){
        if(u==par or vis[u]) continue;
        dfs(u,node);
        subtree[node]+=subtree[u];
    }

}

int centroid(int node,int par,int n){

    for(auto u:adj[node]){
        if(u==par) continue;
        if(!vis[u] and (subtree[u]*2)>n) return centroid(u,node,n);
    }
    return node;

}

void create_centroid_graph(int node,int par){

     sz=0;
    dfs(node,par);
    int c=centroid(node,0,sz);
    parent[c]=par;
    vis[c]=1;
    for(auto u:adj[c]){
        if(vis[u]) continue;

        create_centroid_graph(u,c);
    }

}
 create_centroid_graph(1,0);
