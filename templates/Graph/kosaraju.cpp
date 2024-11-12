#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define testing cout << "testing ";
#define mod 1000000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int>adj[200010];
vector<int>trans[200010];
vector<bool> vis(200010,false);
vector<int>v,x;

void dfs(int node){

    vis[node]=1;
    for(auto u:adj[node]){
        if(vis[u]) continue;
        dfs(u);
    }
    v.push_back(node);
}

void dfs2(int node){


    //cout << node << " ";
    vis[node]=1;
    for(auto u:trans[node]){
        if(vis[u]) continue;
        dfs2(u);
    }
    x.push_back(node);
}

void do_the_honour(){

    int n;cin >> n;
    int m;cin >> m;

    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        trans[y].push_back(x);
    }



    v.clear();
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs(i);

    for(int i=0;i<200010;i++) vis[i]=false;

    reverse(v.begin(),v.end());

    int cc=0;
    vector<vector<int>>ans;
    int xx=0,xy=0;
    for(auto u:v){
        if(vis[u]) continue;
        if(ans.size()==0) xx=u;
        else xy=u;
        x.clear();
        dfs2(u);
        ans.push_back(x);
        cc++;
       // cout << endl;
    }
    if(ans.size()>1){
        cout << "NO" << endl;
        cout << xy<< " " << xx << endl;
    }
    else{
        cout << "YES" << endl;
    }

}

void reset(){
     for(int i=0;i<200010;i++){
        adj[i].clear();
        vis[i]=0;
        v.clear();
        trans[i].clear();
     }
}

int main(){
    optimize();
    int t=1;
   // cin>>t;
    for(int z=1;z<=t;z++){

    reset();
    do_the_honour();


}
    return 0;
}
