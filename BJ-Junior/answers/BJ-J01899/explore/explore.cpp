#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,a[1005][1005]={},b[1005][1005]={},x,y,d,q=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char s;
                cin>>s;
                if(s=='x') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        b[x][y]=1;
        q++;
        for(int i=1;i<=k;i++){
            int dx,dy;
            if(d == 0){
                dx=x;
                dy=y+1;
            }
            if(d == 1){
                dx=x+1;
                dy=y;
            }
            if(d == 2){
                dx=x;
                dy=y-1;
            }
            if(d == 3){
                dx=x-1;
                dy=y;
            }
            if(a[dx][dy]==1){
                x=dx;
                y=dy;
            }
            else{
                d = (d + 1) % 4;
            }
            if(b[x][y]==0) q++;
            b[x][y]=1;
        }
        cout<<q<<'\n';
    }
    return 0;
}
