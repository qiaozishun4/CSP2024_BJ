#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10,K = 1e6+10;
int a[N][N];
char c[N][N];
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
int n,m,k;
int x,y,d;
int T;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        a[x][y] = 1;
        for(int i = 1;i<=k;i++){
            int tx = x+fx[d],ty = y+fy[d];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]=='.'){
                a[tx][ty]++;
                x = tx;
                y = ty;
            }else{
                for(int j = 1;j<=3;j++){
                    k--;
                    if(i>k)break;
                    d = (d+1)%4;
                    tx = x+fx[d],ty = y+fy[d];
                    if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]=='.'){
                        a[tx][ty]++;
                        x = tx;
                        y = ty;
                        break;
                    }
                }
            }
            //cout<<x<<' '<<y<<' '<<c[x][y]<<endl;
        }
        int res = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                //cout<<c[i][j];
                if(a[i][j]>0){
                    res++;
                }
            }
            //cout<<endl;
        }
        printf("%d\n",res);
    }

    return 0;
}
