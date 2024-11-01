#include <cstdio>
#include <cstring>
#define N 1024
#define rep(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[N][N];
bool f[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,r,c,d,nr,nc,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        memset(f,false,sizeof(f));
        scanf("%d%d%d%d%d%d",&n,&m,&k,&r,&c,&d);
        rep(i,1,n)
        {
            scanf("%s",s[i]+1);
        }
        f[r][c]=true;
        while(k--)
        {
            nr=r+dir[d][0];
            nc=c+dir[d][1];
            //printf("++ %d %d %d %d %d %d\n",r,c,d,nr,nc,s[nr][nc]);
            if(!nr||!nc||nr>n||nc>m||s[nr][nc]=='x')
            {
                d=(d+1)&3;
            }
            else
            {
                r=nr,c=nc;
                f[r][c]=true;
            }
            //printf("-- %d %d %d %d %d\n",r,c,d,nr,nc);
        }
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                ans+=f[i][j];
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
