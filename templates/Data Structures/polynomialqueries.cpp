#define MP make_pair
using ap = pair<int,int>;

struct node{
    ap lazy;
    int sum;
    node(){
        lazy ={0,0};
        sum=0;
    }
};

node merge(node a,node b){

    node ans;
    ans.sum=a.sum+b.sum;
    return ans;

}

node t[800033];
int arr[200004];

void push_down(ap cur, int child){

    t[child].lazy.first += cur.first;
    t[child].lazy.second += cur.second;


}

inline int getnth(ap cur,int n){

    return (cur.first+(n-1)*cur.second);
}

inline int getsum(ap cur,int n){

    return (n*(2*cur.first+(n-1)*cur.second))/2;
}

void push(int id,int l,int r){

        if(t[id].lazy==ap{0,0}) return;

        if(l!=r){
            push_down(t[id].lazy,id<<1);
            int mid=(l+r)/2;
            int n=mid+1-(l-1);
            int newa = getnth(t[id].lazy,n);
            push_down({newa,t[id].lazy.second},id<<1|1);
        }


        t[id].sum += getsum(t[id].lazy,r-l+1);
        t[id].lazy={0,0};


}


void update(int id,int l,int r,int lq,int rq,int a,int d){
    push(id,l,r);
    if(lq>r or rq<l) return;
    if(lq<=l and r<=rq){
        t[id].lazy={(l-lq+1),d};
        push(id,l,r);
        return;
    }

    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,a,d);
    update(2*id+1,mid+1,r,lq,rq,a,d);
    t[id]=merge(t[id<<1],t[id<<1|1]);

}


int query(int id,int l,int r, int lq,int rq){


    push(id,l,r);
    if(lq>r or l>rq) return 0;
    if(lq<=l and r<=rq) return t[id].sum;

    int mid = (l + r) / 2;
    return (query(2*id,l,mid,lq,rq)+query(2*id+1,mid+1,r,lq,rq));

}


void build(int id,int l,int r){

    if(l==r){
        t[id].sum=arr[l];
        t[id].lazy={0,0};
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);

}


void do_the_honour(){

    int n;cin >> n;
   int q;cin >> q;

    for(int i=1;i<=n;i++) cin >> arr[i];

    build(1,1,n);
   // cout << query(1,1,n,3,5) << endl;

    while(q--){
        int c,a,b,x; cin >> c;
        if(c==1){
            cin >> a >> b;
            update(1,1,n,a,b,1,1);
        }
        else{
                cin >> a >> b;
            int ans=query(1,1,n,a,b);
            cout << ans << endl;
        }
    }
}
