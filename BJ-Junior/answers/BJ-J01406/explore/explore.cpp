#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long T;
long long n,m,k;
long long ex,ey,ed;
long long sum;
long long p[N][N];
long long vis[N][N];
int fx[]={0,1,0,-1};
int fy[]={1,0,-1,0};
void dfs(long long x,long long y,long long g,long long tmp){
    if(tmp==k)return;
    long long xx=x+fx[g];
    long long yy=y+fy[g];
    if(xx<1||xx>n||yy<1||yy>m||p[xx][yy]==1){
        dfs(x,y,(g+1)%4,tmp+1);
    }
    else{
        if(vis[xx][yy]==0){
            sum+=1;
            vis[xx][yy]=1;

        }
        dfs(xx,yy,g,tmp+1);
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        scanf("%lld%lld%lld",&ex,&ey,&ed);
        string a;
        for(int i=1;i<=n;i++){
            cin>>a;
            for(int j=0;j<m;j++){
                vis[i][j+1]=0;
                if(a[j]=='.'){
                    p[i][j+1]=0;
                }
                else{
                    p[i][j+1]=1;
                }
            }
        }
        sum=1;
        dfs(ex,ey,ed,0);
        printf("%lld\n",sum);
    }

    return 0;
}

