//1-mo's algo

int blk=700;
int cnt[1000001];
int val=0;
int a[200001];

int lb=0,rb=-1;

bool cmp(tuple<int,int,int>&a,tuple<int,int,int>&b){

    if(get<0>(a)/blk != get<0>(b)/blk)
        return  get<0>(a)/blk <= get<0>(b)/blk;
    else return get<1>(a) < get<1>(b);


}

void add(int i){


     val-=cnt[a[i]]*cnt[a[i]]*a[i];
     cnt[a[i]]++;
     val+=cnt[a[i]]*cnt[a[i]]*a[i];


}

void remove(int i){


    val-=cnt[a[i]]*cnt[a[i]]*a[i];
     cnt[a[i]]--;
     val+=cnt[a[i]]*cnt[a[i]]*a[i];
}

void do_the_honour(){

    int n;cin >> n;

    vector<tuple<int,int,int>>v;
int q;cin >> q;

    for(int i=0;i<n;i++) cin >> a[i];




    for(int i=0;i<q;i++){
        int l,r;cin >> l >> r;
        l--,r--;
        v.push_back({l,r,i});
    }

    sort(v.begin(),v.end(),cmp);



    int ans[q];

    for(int i=0;i<q;i++){

        auto [l,r,id]=v[i];
        while(lb>l) lb--,add(lb);
        while(rb<r) rb++,add(rb);

        while(lb<l) remove(lb),lb++;
        while(rb>r) remove(rb),rb--;
        ans[id]=val;
    }

    for(auto u:ans) cout << u << endl;

}
