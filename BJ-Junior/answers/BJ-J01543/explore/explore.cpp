#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,nx,ny,nd;
char a[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=false;
            }
        }
        ans=1;
        b[x][y]=true;
        while(k--){
            if(d==0){
                nx=x;
                ny=y+1;
            }
            if(d==1){
                nx=x+1;
                ny=y;
            }
            if(d==2){
                nx=x;
                ny=y-1;
            }
            if(d==3){
                nx=x-1;
                ny=y;
            }
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
                x=nx;
                y=ny;
                if(!b[nx][ny])
                    ans++;
                b[nx][ny]=true;

            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
