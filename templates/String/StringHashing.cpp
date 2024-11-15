const int N = 2e5 + 9;
const int mod1 = 1e9+21, mod2 = 1e9+9;
const int p1 = 37, p2 = 31;

pair<int,int> pw[N], invpw[N];
int bigMod(int a,int b,int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = 1LL * ans * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return (ans % mod);
}
void preCalc() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
    }
    for(int i = 1; i < N; i++) {
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    }
    int invpw1 = bigMod(p1, mod1 - 2, mod1);
    int invpw2 = bigMod(p2, mod2 - 2, mod2);
    invpw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        invpw[i].first = 1LL * invpw[i-1].first * invpw1 % mod1;
        invpw[i].second = 1LL * invpw[i-1].second * invpw2 % mod2;
    }
}

class  Hash_node {
public:
    int n;
    string s;
    vector<pair<int,int>> hs, prehs;
    Hash_node(){}
    Hash_node(string _s) {
        s = _s;
        n = _s.size();
        hs.resize(n);
        for(int i = 0; i < n; i++) {
            hs[i].first += 1LL * s[i] * pw[i].first % mod1;
            hs[i].first %= mod1;
        }
        for(int i = 0; i < n; i++) {
            hs[i].second += 1LL * s[i] * pw[i].second % mod2;
            hs[i].second %= mod2;
        }
        prehs.resize(n);
        prehs[0].first = hs[0].first;
        for(int i = 1; i < n; i++) {
            prehs[i].first = prehs[i-1].first + hs[i].first;
            prehs[i].first %= mod1;
        }
        prehs[0].second = hs[0].second;
        for(int i = 1; i < n; i++) {
            prehs[i].second = prehs[i-1].second + hs[i].second;
            prehs[i].second %= mod2;
        }
    }
    pair<int,int> getHash(int i,int j) {
        assert(i <= j);
        pair<int,int> ans({0, 0});
        if(i == 0) {
            ans.first = prehs[j].first;
            ans.second = prehs[j].second;
        }
        else {
            ans.first = (prehs[j].first - prehs[i-1].first + mod1) % mod1;
            ans.first = 1LL * ans.first * invpw[i].first % mod1;
            ans.second = (prehs[j].second - prehs[i-1].second + mod2) % mod2;
            ans.second = 1LL * ans.second * invpw[i].second % mod2;
        }
        return ans;
    }
};
```
