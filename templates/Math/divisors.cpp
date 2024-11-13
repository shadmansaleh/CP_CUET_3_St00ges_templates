// Maximal number of divisors of any n-digit number:
// First 18 numbers: 4, 12, 32, 64, 128, 240, 448, 768, 1344, 2304, 4032, 6720, 10752, 17280, 26880, 41472, 64512, 103680
// Number of divisors...
// Euler's totient function…
// first, run a sieve for value sqrt(n);
vector<pair<int, int> > divisors;
void divs(int n) {
	int cnt, tot = 1, i;
	for (i = 0; i < (int)primes.size() && (primes[i] * primes[i]) <= n; i++) {
    if (n % primes[i] == 0) {
    	cnt = 1;
  	        while (n % primes[i] == 0) {
      	    n /= primes[i];
      	    cnt++;
   	}
  	        divisors.push_back(make_pair(primes[i], cnt - 1));
  	        tot *= cnt;
    }
	}
	if (n > 1) {
    	    tot *= 2;
    	    divisors.push_back(make_pair(n, 1));
	}
	printf("Number of divisors %d\n", tot);
	for (i = 0; i < (int)divisors.size(); i++) printf("%d %d\n", divisors[i].first, divisors[i].second);
}
// Number of divisors...
ll NOD(int n) {
	ll ans = 1;
	for (int K = 0; K < sz(divisors); K++) {
    ans *= (ll)(divisors[K].se + 1);
	}
	return ans;
}
// Sum of divisors...
ll SOD(int n) {
	ll ans = 1, cnt;
	for (int K = 0; K < sz(divisors); K++) {
    cnt = divisors[K].fi;
    while (divisors[K].se--) cnt *= (ll)divisors[K].fi;
    ans *= (ll)(cnt - 1) / (divisors[K].fi - 1);
	}
	return ans;
}
