const int MX = 10000001;
int lp[MX];
vector<int> pr;
void linear_sieve() {
  for(int i = 2; i < MX; ++i) {
    if(lp[i] == 0) {lp[i] = i; pr.PB(i);}
    for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && (i * pr[j]) < MX; ++j) lp[i * pr[j]] = pr[j];
  }
}
