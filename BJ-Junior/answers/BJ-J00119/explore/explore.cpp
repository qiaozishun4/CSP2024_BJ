#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1001][1001];
bool dist[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int l=1;l<=t;l++){
        memset(dist,false,sizeof(dist));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        int ans=1;
        for(int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        dist[x][y]=true;
        for(int i=1;i<=k;i++){
            int yy=y,xx=x;
            if(d==0)
                yy++;
            if(d==2)
                yy--;
            if(d==1)
                xx++;
            if(d==3)
                xx--;
            if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='x')
                d=(d+1)%4;
            else{
                x=xx,y=yy;
                if(dist[x][y]==false)
                    ans++;
                dist[x][y]=true;

            }
        }
        printf("%d\n",ans);
    }
}
