
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;

    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];

    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;

        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);

    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);

        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;

        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];

        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;

        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;

            cn[p[i]] = classes - 1;
        }

        c.swap(cn);
        if (classes == n)
            break;
    }

    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n - 1, 0);

    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;

        lcp[rank[i]] = k;

        if (k)
            k--;
    }

    return lcp;
}

//int main() {
//    string s;
//    cin >> s;
//    vector<int> v = suffix_array_construction(s);
//
//    for (int i = 0; i < v.size(); i++)
//        cout << v[i] << " ";
//
//    cout << endl;
//
//    vector<int> lcp = lcp_construction(s, v);
//
//    for (int i = 0; i < lcp.size(); i++)
//        cout << lcp[i] << " ";
//
//    return 0;
//}




int check(int n,int mid, string& pattern,vector<int>&v,vector<int>&lcp,string &s)
{
    int flag = -1, patternSize = pattern.size(),
        suffixStart = v[mid];

    // Check if the suffix can contain the entire pattern
    if (n - suffixStart >= patternSize)
        flag = 0;

    // Compare characters of the pattern and suffix
    for (int i = 0; i < min(n - suffixStart, patternSize);
         i++) {
        if (s[suffixStart + i] < pattern[i])
            return -1;
        if (s[suffixStart + i] > pattern[i])
            return 1;
    }
    return flag;
}




int countocc(string &pat,int n,vector<int>&v,vector<int>&lcp,string &s){


    int left=0,right=n-1;
    int answer=-1;
    int l=left,r=right;

    while(l<=r){

        int mid=(l+r)/2;
        int num=check(n,mid,pat,v,lcp,s);

        if(num==0){
            answer=mid;
            r=mid-1;
        }
        else if(num==1){
            r=mid-1;
        }
        else{
            l=mid+1;
        }

    }

    if(answer==-1){
        return 0;
    }
    left=answer;
    l=left,r=right;
     answer=left;


        while(l<=r){

        int mid=(l+r)/2;
        int num=check(n,mid,pat,v,lcp,s);

        if(num==0){
            answer=mid;
            l=mid+1;
        }
        else if(num==-1){
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }

    right=answer;
    return right-left+1;


}


void do_the_honour(){

    string s,t;cin >> s ;
    string demo=s;

    vector<int> v = suffix_array_construction(demo);
    vector<int> lcp = lcp_construction(demo,v);

    //for(auto u:v) cout << u << " ";
    //cout << endl;
    int k;cin >> k;

    int n=s.size();

    for(int i=0;i<v.size();i++){
        if(i==0){
            int sz=n-v[i];
            if(sz>=k){
                for(int i=v[i];i<=(v[i]+k-1);i++) cout << s[i];
                cout << endl;return;
            }
            else k-=sz;
        }
        else{

            int sz=n-v[i]-lcp[i-1];
            if(sz>=k){
                cout << s.substr(v[i],lcp[i-1]+k) << endl;
                return;
            }
            else k-=sz;

        }
    }

}
