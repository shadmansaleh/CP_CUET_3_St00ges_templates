
struct node{
    int lazy_add;
    int lazy_set;
    int sum;
    node(){
        lazy_add=0;
        lazy_set=0;
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

void push_down(int cur, int child){

    if(t[cur].lazy_set!=0){
        t[child].lazy_set=t[cur].lazy_set;
        t[child].lazy_add=0;
    }
    else{
        if(t[child].lazy_set!=0){
            t[child].lazy_set+=t[cur].lazy_add;

        }
        else{
            t[child].lazy_add+=t[cur].lazy_add;
        }
    }

}

void push(int id,int l,int r){

        if(t[id].lazy_add==0 and t[id].lazy_set==0) return;

        if(l!=r){
            push_down(id,id<<1);
            push_down(id,id<<1|1);
        }

        if(t[id].lazy_add!=0){
            t[id].sum += (r-l+1)*t[id].lazy_add;t[id].lazy_add=0;
        }
        else if(t[id].lazy_set!=0){
            t[id].sum = (r-l+1)*t[id].lazy_set;    t[id].lazy_set=0;
        }



}


void update(int id,int l,int r,int lq,int rq,int val,int utype){
    push(id,l,r);
    if(lq>r or rq<l) return;
    if(lq<=l and r<=rq){
        if(utype==0){
            t[id].lazy_set=val;
        }
        else{
            t[id].lazy_add+=val;
        }
        push(id,l,r);
        return;
    }

    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,val,utype);
    update(2*id+1,mid+1,r,lq,rq,val,utype);
    t[id]=merge(t[id<<1],t[(id<<1)|1]);

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
        t[id].lazy_add=0;
        t[id].lazy_set=0;
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
            cin >> a >> b >> x;
            update(1,1,n,a,b,x,1);
        }
        else if(c==2){
            cin >> a >> b >> x;
            update(1,1,n,a,b,x,0);
        }
        else{
                cin >> a >> b;
            int ans=query(1,1,n,a,b);
            cout << ans << endl;
        }
    }
}

```
range update set and sum
