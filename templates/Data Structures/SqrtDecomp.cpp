int n;
int a[500002];
int blk = 800;
int F[801];

// don't forget to call preprocess();
// static range min query

int getmin(int l, int r)
{

    int lb = l / blk;
    int rb = r / blk;

    int mn = 0;
    if (lb == rb)
    {
        for (int i = l; i <= r; i++)
            mn += a[i];
        return mn;
    }

    for (int i = l; i < min(r, (lb + 1) blk); i++)
        mn += a[i];
    for (int i = lb + 1; i < rb; i++)
        mn += F[i];
    for (int i = blkrb; i <= r; i++)
        mn += a[i];

    return mn;
}

void do_the_honour()
{
    for (int i = 0; i < 600; i++)
        F[i] = 0;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        F[i / blk] += a[i];
    }

    while (k--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << getmin(l, r) << endl;
    }
}
