// Complexity O(n)
const int MX = 1e6;
ll fact[MX + 5], inv[MX + 5];
void factorial() {
	fact[0] = fact[1] = 1;
	for (ll K = 1; K <= MX; K++) fact[K] = fact[K - 1] * K % mod;
	inv[MX] = inverse(fact[MX], mod);
	for (ll K = MX - 1; K >= 1; K--) inv[K] = inv[K + 1] * (K + 1) % mod;
	inv[0] = 1;
}
// function call ...
factorial();
cout << (fact[18] * inv[5] % mod) * inv[13] % mod << "\n";
// Combinatorics problems can be done using stars and bars.The number of ways to put n identical objects into k labeled boxes is (n+k-1)C(n)
// while counting nCr where n,r size is big to get rid of overflow we can do this :
// Code:
minncr(k,n-k);
ll ans=1;
for(ll i=1;i<=k;i++){
   ans = (ans*(n-i+1) )/ i ;
}
