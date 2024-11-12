//finding sum of most frequent values in the subtree of each node;small to large marging
vector<int>adj[200001];
map<int,int>s[200001];
int ans[200001];
int par[200001];
int max_freq_cnt[200001];
int max_freq[200001];
int merge(int a,int b){
    if(s[a].size()<s[b].size()) swap(a,b);
    for(auto u:s[b]) {
        int color=u.first;
        int c=u.second;
        int new_cnt=c+s[a][color];
        s[a][color]+=c;

        if(new_cnt>max_freq[a]){
            max_freq[a]=new_cnt;
            max_freq_cnt[a]=color;
        }
        else if(new_cnt==max_freq[a]) max_freq_cnt[a]+=color;
    }

    return a;

}

int dfs(int node,int p){

    int i=par[node];

    for(auto u:adj[node]){
        if(p==u) continue;
        i=merge(i,dfs(u,node));
    }



    ans[node]=max_freq_cnt[i];
    return i;
}


void do_the_honour(){

    int n;cin >> n;
    int color[n+1];
    for(int i=1;i<=n;i++) cin >> color[i];

    for(int i=1;i<=n;i++){
        s[i][color[i]]++;
        par[i]=i;
        max_freq[i]=1;
        max_freq_cnt[i]+=color[i];
    }

    for(int i=1;i<n;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";


}
