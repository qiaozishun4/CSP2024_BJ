#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
int cnt,p[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
string s[1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cnt=0;
        memset(p,0,sizeof(p));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            cin>>s[i];
            s[i]=' '+s[i];
        }
        if(!p[x][y]){
            cnt++;
            p[x][y]=1;
        }
        while(k--){
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[xx][yy]=='.'){
                x=xx;
                y=yy;
            }else{
                d=(d+1)%4;
            }
            if(!p[x][y]){
                cnt++;
                p[x][y]=1;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
