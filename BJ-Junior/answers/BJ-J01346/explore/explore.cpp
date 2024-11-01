#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    char s[1009][1009];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>s[i][j];
        }
    }
    set<pair<int,int>> p;
    p.insert(make_pair(x,y));
    for(int a=1;a<=k;a++){
        int xp,yp;
        if (d==0) { xp=x; yp=y+1; }
        if (d==1) { xp=x+1; yp=y; }
        if (d==2) { xp=x; yp=y-1; }
        if (d==3) { xp=x-1; yp=y; }
        if (1<=xp && xp<=n && 1<=yp && yp<=m && s[xp][yp]=='.') {
            x=xp; y=yp;
            p.insert(make_pair(x,y));
            //cout<<"move to: "<< x<<"  "<<y<<endl;
        }
        else {
            d = (d + 1) % 4;
            //cout<<"turn right"<<endl;
        }
    }
    int r=p.size();
    //for(pair<int,int> aa : p) {
    //    cout<<aa.first<<"  "<<aa.second<<endl;
    //}
    cout<<r<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
