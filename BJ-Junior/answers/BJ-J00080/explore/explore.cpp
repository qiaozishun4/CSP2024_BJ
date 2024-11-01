#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+5;
int t,n,m,k,x,y,d,ans;
char s[maxn][maxn];
bool v[maxn][maxn];

int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int j=1;j<=n;j++){
            scanf("%s",s[j]+1);
        }
        memset(v,0,sizeof(v));
        v[x][y]=1;
        ans=1;
        for(int j=1;j<=k;j++){
            int a=x+dis[d][0];
            int b=y+dis[d][1];
            if(a<=n && a>=1 && b<=m && b>=1 && s[a][b]=='.'){
                if(!v[a][b]){
                    ans++;
                    v[a][b]=1;
                }
                x=a,y=b;
            }
            else{
                d=(d+1)%4;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
