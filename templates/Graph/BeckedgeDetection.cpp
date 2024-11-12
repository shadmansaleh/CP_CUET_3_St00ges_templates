void Graph::dfs(int v, int parent) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    subtreeSize[v] = 1;

    for (int to : adj[v]) {
        if (to == parent) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // Back edge detected between v and to
                int x = subtreeSize[to];
                int y = vertices - x;
                totalPairs = min(totalPairs, calculatePairs(x) + calculatePairs(y));
            }
            subtreeSize[v] += subtreeSize[to];
        }
    }
}

void Graph::countSubtreeSizes(int v, int parent) {
    visited[v] = true;
    subtreeSize[v] = 1;
    for (int to : adj[v]) {
        if (to != parent && !visited[to]) {
            countSubtreeSizes(to, v);
            subtreeSize[v] += subtreeSize[to];
        }
    }
}
