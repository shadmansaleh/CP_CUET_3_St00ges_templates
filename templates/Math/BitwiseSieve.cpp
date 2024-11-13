// Bitwise - sieve :- prime number generator;
// 0 for prime, 1 for not prime; >> Not sure ... #define MX 10000000
int marked[MX / 64 + 2];
vector<int> primes;
#define mark(x) marked[x >> 6] |= (1 << ((x & 63) >> 1)) 
#define check(x)(marked[x >> 6] & (1 << ((x & 63) >> 1)))
bool isPrime(int x) { return (x > 1) && ((x == 2) || ((x & 1) && (!(check(x))))); }
void sieve(int n) {
	int i, j;
	primes.push_back(2);
	for (i = 3; i * i <= n; i += 2) {
    if (!check(i)) {
    	primes.push_back(i);
     	for (j = i * i; j <= n; j += i << 1) mark(j);
    }
	}
}
