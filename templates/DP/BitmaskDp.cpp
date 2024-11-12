//bitmask DP: number of permutaton of length n such that no two adjacent elements diff are greater than k

ll int n,k;
vector<ll int>v;

ll dp[17][(1<<17)];
ll func(int id,int mask){

    if(mask==0) return 1;
    if(dp[id][mask]!=-1) return dp[id][mask];
    ll int ans=0;
    for(ll int i=0;i<=(n-1);i++){
        if(abs(i-id)>k) continue;
        if(mask&(1<<i)){
            ans+=func(i,mask^(1<<i));
        }
    }
    return dp[id][mask]=ans;
}

void do_the_honour(){

    cin >> n >> k;
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++) v.push_back(i);

    ll ans=0;
    for(int i=0;i<n;i++) ans+=func(i,((1<<n)-1)^(1<<i)) ;
    cout << ans << endl;

}
