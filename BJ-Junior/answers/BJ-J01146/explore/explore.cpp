#include<iostream>
#include<cstring>
using namespace std;
#define maxn (int)1e3
#define maxm (int)1e3
int t,n,m,k,x,y,d;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char c[maxn+10][maxm+10];
bool visited[maxn+10][maxm+10];
int main()
{
    //freopen("explore.in","r",stdin);
    //freopen("explore.out","w",stdout);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        memset(visited,false,sizeof visited);
        for(int i=0;i<n;i++)scanf("%s",c[i]);
        x--;
        y--;
        for(int i=0;i<k;i++)
        {
            visited[x][y]=true;
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&c[nx][ny]=='.')
            {
                x=nx;
                y=ny;
            }
            else d=(d+1)%4;
        }
        visited[x][y]=true;
        d=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)d+=visited[i][j];
        printf("%d\n",d);
    }
    return 0;
}
//CSP RP++
//Good luck!
