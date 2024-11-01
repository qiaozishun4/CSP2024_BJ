#include<bits/stdc++.h>
using namespace std;
int T;
bool ma[1005][1005],flag[1005][1005];
int n,m,k;
int xst,yst,d;
int cnt=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    int c=1;
    while(c<=T){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&xst,&yst,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char pos;
                cin>>pos;
                if(pos=='.')ma[i][j]=1;
                else ma[i][j]=0;
                flag[i][j]=0;
            }
        }
        flag[xst][yst]=1;
        int nx=xst,ny=yst;
        for(int i=1;i<=k;i++){
            if(d==0){
                int nxx=nx,nyy=ny+1;
                if(nxx>=1&&nxx<=n&&nyy>=1&&nyy<=m&&ma[nxx][nyy]){
                    if(flag[nxx][nyy]==0){
                        cnt++;
                        flag[nxx][nyy]=1;
                    }
                    nx=nxx;
                    ny=nyy;
                }else d=(d+1)%4;
                continue;
            }else if(d==1){
                int nxx=nx+1,nyy=ny;
                if(nxx>=1&&nxx<=n&&nyy>=1&&nyy<=m&&ma[nxx][nyy]){
                    if(flag[nxx][nyy]==0){
                        cnt++;
                        flag[nxx][nyy]=1;
                    }
                    nx=nxx;
                    ny=nyy;
                }else d=(d+1)%4;
                continue;
            }else if(d==2){
                int nxx=nx,nyy=ny-1;
                if(nxx>=1&&nxx<=n&&nyy>=1&&nyy<=m&&ma[nxx][nyy]){
                    if(flag[nxx][nyy]==0){
                        cnt++;
                        flag[nxx][nyy]=1;
                    }
                    nx=nxx;
                    ny=nyy;
                }else d=(d+1)%4;
                continue;
            }else if(d==3){
                int nxx=nx-1,nyy=ny;
                if(nxx>=1&&nxx<=n&&nyy>=1&&nyy<=m&&ma[nxx][nyy]){
                    if(flag[nxx][nyy]==0){
                        cnt++;
                        flag[nxx][nyy]=1;
                    }
                    nx=nxx;
                    ny=nyy;
                }else d=(d+1)%4;
                continue;
            }
        }
        printf("%d\n",cnt);
        cnt=1;
        c++;
    }
    return 0;
}
