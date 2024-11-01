#include<bits/stdc++.h>
using namespace std;
char c[2001][2001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        if(k==1) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                        cin>>c[i][j];
                }
            }
            if(d==0) {
                if(y+1<=m && x<=n && c[x][y+1]=='.') cout<<2<<endl;
                else cout<<1<<endl;
            }else if(d==1) {
                if(x+1<=n && y<=m && c[x+1][y]=='.') cout<<2<<endl;
                else cout<<1<<endl;
            }else if(d==2) {
                if(x<=n && y<=m && c[x][y-1]=='.') cout<<2<<endl;
                else cout<<1<<endl;
            }else {
                if(x<=n && y<=m && c[x-1][y]=='.') cout<<2<<endl;
                else cout<<1<<endl;
            }
        }else if(n==1) {
            string s;
            cin>>s;
            if(d==1||d==3) cout<<n<<endl;
            else cout<<n+1<<endl;
        }
    }

    return 0;
}
