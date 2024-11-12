vector<pair<int,int>>vp;
vector<int>adj[200001];
set<int>seen;
vector<int>path;
void dfs(int node){

    while(!adj[node].empty()){
        int x=adj[node].back();
        adj[node].pop_back();
            dfs(x);

    }
    path.push_back(node);
}

void do_the_honour(){

    int n,m;cin >> n >> m;

    int in[n+1]={0},out[n+1]={0};
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        vp.push_back({x,y});
        in[y]++,out[x]++;
        adj[x].push_back(y);
    }

    int c=0;
    int s,e,ss=0,ee=0;
    for(int i=1;i<=n;i++){
        if(in[i]-out[i]==0) c++;
        if(in[i]-out[i]==1) ee++,e=i;
        if(in[i]-out[i]==-1) ss++,s=i;
    }

    if(c!=n-2 or s!=1 or e!=n or ee!=1 or ss!=1) cout << "IMPOSSIBLE";
    else{
        dfs(1);
        if(path.size()!=m+1) cout << "IMPOSSIBLE";
        else{
            reverse(path.begin(),path.end());
            for(auto u:path) cout << u << " ";
        }
    }
}
