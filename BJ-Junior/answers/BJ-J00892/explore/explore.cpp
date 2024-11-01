#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,sx,sy,sd;
long long fang,xx,yy,cnt;
char a[2005][2005];
bool visit[2005][2005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(long long x=1;x<=T;++x){
        cnt=0;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;

        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j){
                visit[i][j]=0;
                a[i][j]=0;
            }
        }
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j){
                cin>>a[i][j];
            }
        }
        fang=sd;
        xx=sx;
        yy=sy;
        visit[sx][sy]=1;
        for(long long d=1;d<=k;++d){
            if(fang==0){
                yy++;
                if(yy<=m&&a[xx][yy]=='.'){
                    visit[xx][yy]=1;
                }else{
                    fang=(fang+1)%4;
                    yy--;
                }
            }else if(fang==1){
                xx++;
                if(xx<=n&&a[xx][yy]=='.'){
                    visit[xx][yy]=1;
                }else{
                    fang=(fang+1)%4;
                    xx--;
                }
            }else if(fang==2){
                yy--;
                if(yy>=1&&a[xx][yy]=='.'){
                    visit[xx][yy]=1;
                }else{
                    fang=(fang+1)%4;
                    yy++;
                }
            }else if(fang==3){
                xx--;
                if(xx>=1&&a[xx][yy]=='.'){
                    visit[xx][yy]=1;
                }else{
                    fang=(fang+1)%4;
                    xx++;
                }
            }
        }
        for(long long xxx=1;xxx<=n;xxx++){
                for(long long yyy=1;yyy<=m;yyy++){
                    if(visit[xxx][yyy]==1){
                        cnt++;
                    }
                }
            }
        cout<<cnt<<endl;
    }
}
