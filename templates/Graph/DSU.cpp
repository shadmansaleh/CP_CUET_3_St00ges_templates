const int N=2e5+10;
int parent[N];
int Size[N];

void make(int v) {parent[v]=v;Size[v]=1;}

int Find(int v){
    if(v==parent[v]) return v;
    return (parent[v]=Find(parent[v]));
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(Size[a]<Size[b]) swap(a,b);
    if(a!=b) parent[b]=a;
    Size[a]+=Size[b];
}
