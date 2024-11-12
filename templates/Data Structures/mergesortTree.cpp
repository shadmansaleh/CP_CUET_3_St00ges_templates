

vector<int> treee[800008];

int arr[200002];
//give call init(1,1,n);



void init(int node,int b,int e){

    if(b==e){
        int x=arr[b];
    treee[node].push_back(x);
        return;
    }
    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    int i=0;
    int j=0;
    while(i<treee[left].size() and j<treee[right].size()){
        int x=treee[left][i];
        int y=treee[right][j];
        if(x<=y){
            treee[node].push_back(x);
            i++;
        }
        else treee[node].push_back(y),j++;
    }

    while(i<treee[left].size()){
        int x=treee[left][i];
        treee[node].push_back(x);
            i++;
    }

    while(j<treee[right].size()){
        int x=treee[right][j];
        treee[node].push_back(x);
            j++;
    }

}

int query(int node,int b,int e,int i, int j){

    if(i>e or j<b) return 0;
    if(b>=i and e<=j) {
    return treee[node].end()-(upper_bound(treee[node].begin(),treee[node].end(),j));
    }

    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);



    return p1+p2;
}




void do_the_honour(){

    int n,k;cin >> n >> k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];

    unordered_map<int,int>mp;
    for(int i=n;i>=1;i--){
        if(mp[a[i]]==0){
           arr[i]=n+1;
           mp[a[i]]=i;
        }
        else{
            arr[i]=mp[a[i]];
            mp[a[i]]=i;
        }
    }

    init(1,1,n);

    while(k--){
        int l,r;cin >> l >> r;
        cout << query(1,1,n,l,r) << endl;
    }

}
