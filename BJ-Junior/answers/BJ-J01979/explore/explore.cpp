#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
string s[1005];
int a[1005][1005];
int to[4][2]={{0,1},
              {1,0},
              {0,-1},
              {-1,0}};
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            cin>>s[i];
            s[i]='#'+s[i];
        }
        int ans=1;
        for(int i=1;i<=k;i++) {
            int xx=x+to[d][0];
            int yy=y+to[d][1];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && s[xx][yy]=='.') {
                x=xx;
                y=yy;
                if(a[x][y]==0) {
                    ans++;
                }
                a[x][y]=1;
            } else {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}