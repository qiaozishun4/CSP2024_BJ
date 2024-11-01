#include <iostream>
using namespace std;
long long T,n,m,k,x,y,x1,y1,d,res;
char mapp[1005][1005],visited[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    for (int i=1;i<=T;i++) {
        res=0;
        //shuru
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        visited[x][y]=1;
        for (int j=1;j<=n;j++) {
            for (int l=1;l<=m;l++) {
                cin >> mapp[j][l];
            }
        }
        //zhuti
        for (int j=1;j<=k;j++) {
            x1=x;
            y1=y;
            if (d==0) {
                y1=y+1;
            }
            else if (d==1) {
                x1=x+1;
            }
            else if (d==2) {
                y1=y-1;
            }
            else if (d==3) {
                x1=x-1;
            }
            if (mapp[x1][y1]=='.'&&1<=x1&&x1<=n&&1<=y1&&y1<=m) {//ruguokeyizou
                visited[x1][y1]=1;
                x=x1;
                y=y1;
            }
            else {
                d=(d+1)%4;
            }
            //cout  << j << " " << d <<" "<<x1<<" "<< x << " " <<y1<<" "<< y  <<" "<<res <<endl;
        }
        //chushihua
        for (int j=1;j<=n;j++) {
            for (int l=1;l<=m;l++) {
                if (visited[j][l]==1) {
                    res++;
                    visited[j][l]=0;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
