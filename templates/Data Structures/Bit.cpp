int bit[100005];
void update(int i,int x){
    for(;i<=n;i+=(i&-i)){
        bit[i]+=x;
    }
}

int sum(int i){

    long ans=0;
    for(;i>0;i-=(i&-i)) ans+=bit[i];
    return ans;
}
