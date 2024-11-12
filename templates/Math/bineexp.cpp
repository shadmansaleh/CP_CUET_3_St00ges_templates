ll binexp(ll int a,ll int b,ll int m){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return res;
}
