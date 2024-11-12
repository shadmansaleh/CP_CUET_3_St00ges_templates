int area(vector<pair<int, int>> vertices){


    int n=vertices.size();



    int area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[i].second * vertices[j].first;
    }

    return abs(area);


}


int latticeonboundary(pair<int,int>p1,pair<int,int>p2){

    int a=abs(p1.first-p2.first);
    int b=abs(p1.second-p2.second);

    return (__gcd(a,b)-1);

}



//A=i+b/2-1
void do_the_honour(){

    int n;cin >> n;
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        vp.push_back({x,y});
    }

    int total=area(vp)/2;

    int boundary=0;

    for(int i=0;i<n;i++){
        boundary+= latticeonboundary(vp[i],vp[(i+1)%n]);
    }

    boundary+=n;

    cout << total+1-(boundary/2) << " " << boundary << endl;

}
