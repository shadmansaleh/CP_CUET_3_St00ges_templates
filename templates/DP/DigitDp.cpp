//digit dp template: find number from a to b such that that number and sum of digits of that number are divisible by k
ll dp[10][82][2][1000];
int k;
ll func(string &s,int pos=0,int sum=0,int tight=1,int x=0){

    if(pos==s.size()){
        if(x%k==0 and sum%k==0) return 1;
        else return 0;
    }

    if(dp[pos][sum][tight][x]!=-1) return dp[pos][sum][tight][x];
    ll res=0;
    if(tight==1){

            for(int i=0;i<(s[pos]-'0');i++){
                res+=func(s,pos+1,sum+i,0,(x*10+i)%k);
            }
            res+=func(s,pos+1,sum+(s[pos]-'0'),1,(x*10+(s[pos]-'0'))%k);
    }
    else{
        for(int i=0;i<=9;i++){
            res+=func(s,pos+1,sum+i,0,(x*10+i)%k);
        }
    }

    return dp[pos][sum][tight][x]=res;
}

void do_the_honour(int t){

    memset(dp,-1,sizeof(dp));
    int a,b;cin >> a >> b >>k;
    a--;
    string x=to_string(a);
    string y=to_string(b);

    ll cnt1=func(x);
    memset(dp,-1,sizeof(dp));
    ll cnt2=func(y);
    cout << "Case " << t << ": " << cnt2 - cnt1 << endl;

}
