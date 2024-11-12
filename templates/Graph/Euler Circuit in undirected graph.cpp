
void dfs(int node){

    set<int>&ev=adj[node];
    while(!ev.empty()){
        int u=*ev.begin();
        ev.erase(ev.begin());
        adj[u].erase(node);
        dfs(u);
    }
    path.push_back(node);

}

void do_the_honour(){

    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    for(int i=1;i<=n;i++){
        if(adj[i].size()&1){
            cout << "IMPOSSIBLE" << endl;//every node must have even degree;
            return;
        }
    }

    dfs(1);
    if(path.size()!=m+1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto u:path) cout << u << " ";
    }
}
