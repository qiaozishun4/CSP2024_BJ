#include <bits/stdc++.h>
using namespace std;
const int N=1005;
bool a[N][N],b[N][N];
int T;
int n, m, k;
int x, y, d;
char c;
long long int ans=0;
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>c;
                if(c=='x')a[i][j]=0;
                else a[i][j]=1;
            }
        }
        b[x][y]=1;
        while(k){
            if(d==0) {
                if(y+1<=m&&a[x][y+1]) {
                    y++;
                    if(!b[x][y]){ans++;b[x][y]=1;}
                }else {
                    d++;
                }
            }else if(d==1) {
                if(x+1<=n&&a[x+1][y]) {
                    x++;
                    if(!b[x][y]){ans++;b[x][y]=1;}
                }else {
                    d++;
                }
            }else if(d==2) {
                if(y-1>=1&&a[x][y-1]) {
                    y--;
                    if(!b[x][y]){ans++;b[x][y]=1;}
                }else {
                    d++;
                }
            }else {
                if(x-1>=1&&a[x-1][y]) {
                    x--;
                    if(!b[x][y]){ans++;b[x][y]=1;}
                }else {
                    d=0;
                }
            }
            //cout<<x<<" "<<y<<" "<<d<<" "<<ans<<"\n";
            k--;
        }
        cout<<ans<<"\n";
        T--;
    }
    return 0;
}
