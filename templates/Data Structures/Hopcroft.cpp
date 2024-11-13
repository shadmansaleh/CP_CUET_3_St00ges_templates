const int mx=1e4+10;
vector<int>adj[mx];
map<pair<int,int>,int>cost;
int pairU[mx],pairV[mx],dist[mx],a,b;
bool bfs()
{
    queue<int> Q;
    for (int u=1; u<=a; u++)
    {
        if (pairU[u]==0)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = inf;
    }
    dist[0] = inf;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[0])
        {
            for (auto it : adj[u])
            {
                int v = it;
                if (dist[pairV[v]] == inf)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[0] != inf);
}
bool dfs(int u)
{
    if (u != 0)
    {
         for (auto it : adj[u])
            {
                int v = it;
            if (dist[pairV[v]] == dist[u]+1)
            {

                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}

int hopcroftKarp()
{
    for (int u=0; u<=a; u++)
        pairU[u] = 0;
    for (int v=0; v<=a; v++)
        pairV[v] = 0;
    int result = 0;
    while (bfs())
    {
        for (int u=1; u<=a; u++)

            if (pairU[u]==0 && dfs(u)){
                result++;
            }
    }
    return result;
}
 main()
{
    cin>>a>>b;
    int x,y;
    for(int i=0;i<b;i++){
        cin>>x>>y;
        adj[y].push_back(x);
        int cost;
        cin>>cost;
        cost[{y,x}]=cost;
    }
    int ans=hopcroftKarp();
}
