vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}
void initofHLD(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}
vector<int> tree(400001), arr(100001);
int arrtotree[300001];
void init(int n)
{
    for (int i = 0; i < n; i++)
        tree[n + i] = arr[i];

    for (int i = n - 1; i >= 1; i--)
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

void update(int pos, int value, int n)
{
    pos += n;
    tree[pos] = value;

    while (pos > 1) {
        pos >>= 1;
        tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }
}

int segquery(int left, int right, int n)
{
    left += n;
    right += n + 1; // inclusive range
    int mi = (int)-1;

    while (left < right) {
        if (left & 1) {
            mi = max(mi, tree[left]);
            left++;
        }
        if (right & 1) {
            right--;
            mi = max(mi, tree[right]);
        }
        left >>= 1;
        right >>= 1;
    }
    return mi;
}

int query(int a, int b, int n) {
    int res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]]) swap(a, b);
        res = max(res, segquery(pos[head[b]], pos[b], n));
        b = parent[head[b]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, segquery(pos[a], pos[b], n));
    return res;
}

void do_the_honour() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    initofHLD(adj);

    arr.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; ++i) arr[pos[i]] = a[i];
    init(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1, n) << ' ';
        } else {
            int s, x;
            cin >> s >> x;
            s--;
            update(pos[s], x, n);
        }
    }
    cout << '\n';
}
