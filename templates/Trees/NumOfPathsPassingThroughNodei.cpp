
int dp[32][200001];
int level[200001];
vector<int>adj[200001];

void dfs(int node,int par){

    for(auto u:adj[node]){
        if(u==par) continue;
        level[u]=level[node]+1;
        dp[0][u]=node;
        dfs(u,node);
    }


}

int c[200001];


void dfs22(int node,int par){

    for(auto u:adj[node]){
        if(u==par) continue;
        dfs22(u,node);
        c[node]+=c[u];
    }

}

void do_the_honour(){

    int n,m;cin >> n >> m ;

    for(int i=2;i<=n;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    level[1]=0;
 dfs(1,0);
    dp[0][1]=0;


    for(int i=1;i<=24;i++){
        for(int j=1;j<=n;j++) dp[i][j]=dp[i-1][dp[i-1][j]];
    }

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        int x=a,y=b;

        if(level[a]<level[b]) swap(a,b),swap(x,y);
        int diff=level[a]-level[b];

        for(int i=0;i<=24;i++){
            if(diff&(1<<i)){
                a=dp[i][a];
            }
        }
        int node=-1;
        if(a==b){
            node=a;
        }else{

            for(int ii=24;ii>=0;ii--){
                if(dp[ii][a]!=dp[ii][b]){
                    a=dp[ii][a];
                    b=dp[ii][b];
                }
            }
            node=dp[0][a];

        }


        c[x]++,c[y]++,c[node]--;
        if(dp[0][node]>0) c[dp[0][node]]--;


    }

    dfs22(1,0);
    for(int i=1;i<=n;i++) cout << c[i] << " ";
}
