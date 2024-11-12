const int N=2e5+3;
const int INF=1e15+10;
vector<pair<int,int>>g[N];
priority_queue<int>d[200001];
void dijkstra(int k){

    vector<int>dist(N,INF);
    vector<bool>vis(N,0);

    multiset<pair<int,int>>st;

    st.insert({0,1});

    while(st.size()>0){
        auto node=*st.begin();
        st.erase(st.begin());
        int v=node.second;
        int v_dis=node.first;

        if(d[v].top()<v_dis) continue;

        for(auto child:g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(v_dis+wt<d[child_v].top()){
                d[child_v].pop();
                int l=v_dis+wt;
                d[child_v].push(v_dis+wt);
                st.insert({l,child_v});


            }
        }
    }

}
void do_the_honour(){

    int n,m,k;cin >> n >> m >> k;

    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            d[i].push(INF);
        }
    }
    d[1].pop();
    d[1].push(0);
    dijkstra(k);
    vector<int>v;
    //cout << d[n].size() << endl;
    while(!d[n].empty()){
        v.push_back(d[n].top());
        d[n].pop();
    }
    while(!v.empty()){
        cout << v.back() << " ";
        v.pop_back();
    }
    cout << endl;

}
