#include<bits/stdc++.h>
using namespace std;
int t;
int way[4][2]={0,1,1,0,0,-1,-1,0};
int mapp[1005][1005];
int n,m,k;
int sx,sy,sf;
int myans=0;
void explore(int n,int m,int k,int sx,int sy,int sf){
    myans=1;
    for(int i=1;i<=k;i++){
        int nx=0,ny=0;
        nx=sx+way[sf][0];
        ny=sy+way[sf][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&nx&&mapp[nx][ny]!=1){
            if(mapp[nx][ny]==0){
                myans++;
                mapp[nx][ny]=2;
            }
            sx=nx;
            sy=ny;
        }
        else{
            sf=(sf+1)%4;
        }
    }
    return  ;
}
int main(){
     freopen("explore.in","r",stdin);
     freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&sx,&sy,&sf);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a;
                cin>>a;
                if(a=='x'){
                    mapp[i][j]=1;
                }
                else mapp[i][j]=0;
            }
        }
        mapp[sx][sy]=2;
        explore(n,m,k,sx,sy,sf);
       printf("%d\n",myans);
    }
    return 0;
}
