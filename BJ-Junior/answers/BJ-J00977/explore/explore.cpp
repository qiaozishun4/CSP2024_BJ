#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,sum,b[1000][1000];
long long fx,fy;
char a[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int z=1;z<=t;z++){
        sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                fx=x,fy=y+1;
                if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]=='.'){
                    x=fx,y=fy;b[fx][fy]=1;
                }else d=(d+1)%4;
            }
            else if(d==1){
                fx=x+1,fy=y;
                if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]=='.'){
                    x=fx,y=fy;b[fx][fy]=1;
                }else d=(d+1)%4;
            }
            else if(d==2){
                fx=x,fy=y-1;
                if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]=='.'){
                    x=fx,y=fy;b[fx][fy]=1;
                }else d=(d+1)%4;
            }
            else if(d==3){
                fx=x-1,fy=y;
                if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]=='.'){
                    x=fx,y=fy;b[fx][fy]=1;
                }else d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
