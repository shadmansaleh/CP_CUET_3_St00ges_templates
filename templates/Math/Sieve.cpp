// sieve :- prime number generator;
// 0 for prime, 1 for not prime;
vector<int> primes;
vector<bool> mark(1000002);
void sieve(int n) {
	int i, j, limit = sqrt(n*1.) + 2;
	mark[1] = 1;
	for(i = 4; i<=n; i+=2) mark[i] = 1;
	primes.push_back(2);
	for(i = 3; i <= n; i += 2){
    if(!mark[i]){
   	primes.push_back(i);
    	if(i<=limit){
  	    for(j = i*i; j <= n; j += i*2){
	        mark[j] = 1;  
  	    }
     	}
    }
	}
}