 int k;
    int m; cin >> n >> m >>k;
    int src=0,dest=n+m+1;
    for (int i = 0; i < k; i++) {
        int x, y, w = 1; cin >> x >> y;
        capacity[x][y+n] = w;


        adj[x].push_back(y+n);
        adj[y+n].push_back(x);
        adj2[x][y+n] = 1;


    }

    for(int i=1;i<=n;i++)
    {
        adj[src].push_back(i);
        adj[i].push_back(src);
        capacity[src][i]=1;
        adj2[0][i]=1;
    }
    for(int i=1;i<=m;i++)
    {

        adj[i+n].push_back(dest);
        adj[dest].push_back(i+n);
        capacity[i+n][dest]=1;
        adj2[n+i][dest]=1;
    }

    cout << maxflow(src, dest) << endl;

    fill(vis, vis + 10001, 0); // Reset the visited array
    dfs(0);

    for (int i = 1; i <= n; i++) {
        for (int j = n+1; j <= n+m; j++) {
            if ((capacity[i][j]==0) and (adj2[i][j]==1)) {
                ans.push_back({i, j-n});
            }
        }
    }

    for (auto u : ans) cout << u.first << " " << u.second << endl;
