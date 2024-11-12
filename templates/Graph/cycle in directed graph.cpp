vector<int>adj[200001];
vector<vector<int>>v;
int par[200001];
int color[200001];
bool f=0;
void dfs(int node,int pp){

    if(color[node]==2) return;
    if(f) return;
    if(color[node]==1){
        vector<int>x;
        int p=pp;
        x.push_back(p);
        while(p!=node){            p=par[p];

            x.push_back(p);
        }
        reverse(x.begin(),x.end());
        v.push_back(x);
        if(x.size()>=2) f=1;
        x.clear();
        return ;
    }
    color[node]=1;
    par[node]=pp;

    for(auto u:adj[node]){
        if(u==pp) continue;
        dfs(u,node);
    }
    color[node]=2;

}
void do_the_honour(){

    int n,m;cin >> n >> m;

    map<pair<int,int>,bool>mp;

    int b=-1,cc=-1;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        mp[{x,y}]=1;
        if(mp[{y,x}]){
            b=x,cc=y;
        }
        //adj[y].push_back(x);
    }
    if(b!=-1){
        cout << 3 << endl;
        cout << b << " " << cc << " " << b << endl;
        return;
    }

    for(int i=1;i<=n;i++){
        if(color[i]!=0) continue;
        dfs(i,0);
    }

    int sz=0;
    vector<int>ans;
    for(auto u:v){
        if(sz<u.size()){
            sz=u.size();
            ans=u;
        }
    }
    if(sz>=3){
        cout << ans.size()+1 << endl;
        for(auto u:ans) cout << u << " ";
        cout << ans[0] << endl;
        cout << endl;

    }
    else cout << "IMPOSSIBLE" << endl;



}
