array<ll,4> mul(array<ll,4>x, array<ll,4>y){

    ll a=x[0],b=x[1],c=x[2],d=x[3];
    ll e=y[0],f=y[1],g=y[2],h=y[3];

    ll m=((a*e)%mod+(b*g)%mod)%mod;
    ll n=((a*f)%mod+(b*h)%mod)%mod;
    ll o=((c*e)%mod+(d*g)%mod)%mod;
    ll p=((c*f)%mod+(d*h)%mod)%mod;
    return {m,n,o,p};


}

array<ll,4> Find(ll n){

    if(n==1) return {1,1,1,0};
    array<ll,4>x=Find(n/2);

    if(n&1) return mul(mul(x,x),Find(1));
    else return mul(x,x);

}

void do_the_honour(){

    ll int n;cin >> n;

    if(n==0) cout << 0;
    else if(n==1) cout << 1;
    else if(n==2) cout << 1;
    else if(n==3) cout << 2;
    else{
        cout << Find(n-1)[0];
    }

}
