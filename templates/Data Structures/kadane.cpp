sum = ans = ara[0];
int u = 0, v = 0;
for (int K = 1; K < n; K++) {
	if (sum + ara[K] >= ara[K]) {
    	    sum += ara[K];
    	    v++;
	} else {
    	    sum = ara[K];
    	    u = v = K;
	}
	if (sum > ans) {
    	    ans = sum;
    	    ans_l = u;
    	    ans_r = v;
	}
}
