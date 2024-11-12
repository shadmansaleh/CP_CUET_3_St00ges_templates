int tree[400004];
int arr[100001];
//give call init(1,1,n);
void init(int node,int b,int e){

    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e,int i, int j){

    if(i>e or j<b) return 0;
    if(b>=i and e<=j) return tree[node];

    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int newvalue){
    if(i>e or i<b) return;
    if(b>=i and e<=i){
        tree[node]=newvalue;
        return;
    }
    int left=2*node;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

////------lazy propagation-----

struct info{
    ll prop,sum;
}tree[400001];

int query(int node,int b, int e, int i, int j,int carry=0){
    if(i>e or j<b) return 0;
    if(b>=i and e<=j){
        return tree[node].sum+carry*(e-b+1);
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int p1=query( left, b, mid, i, j,carry+tree[node].prop);
    int p2=query( right, mid+1, e, i,j,carry+tree[node].prop);
    return p1+p2;

}

void update(int node,int b,int e,int i,int j,ll x){
    if(i>e or j<b) return;
    if(b>=i and e<=j){

        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }

    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
