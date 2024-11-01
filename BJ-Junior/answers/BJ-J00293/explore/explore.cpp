#include <iostream>
#include <cstring>
using namespace std;
char a[1005][1005];
bool v[1005][1005];
int n,m,k,x,y,d;
int xd[4]={0,1,0,-1};
int yd[4]={1,0,-1,0};
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        memset(v,0,sizeof(v));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
            }
        }
        v[x][y]=1;
        for(int i=1;i<=k;i++) {
            int x1=x+xd[d];
            int y1=y+yd[d];
            if(1<=x1 && x1<=n && 1<=y1 && y1<=m && a[x1][y1]=='.') {
                x=x1;
                y=y1;
                v[x][y]=1;
            }
            else {
                d=(d+1)%4;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(v[i][j]) {
                    cnt++;
                    //cout<<i<<" "<<j<<"  ";
                }
            }
            //cout<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
