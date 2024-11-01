#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
#define N 1005
char g[N][N];
int b[N][N];

int T,n,m,k,x,y,d;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

void js()
{
    b[x][y]=1;
    for(int i=0;i<k;i++)
    {
        int xx=x+dx[d],yy=y+dy[d];
        if(xx>=0 && xx<n && yy<m && yy>=0 && g[xx][yy]=='.')
        {
            x=xx,y=yy;
            b[x][y]=1;
        }
        else{
            d=(d+1)%4;
        }
    }
}




int main()
{
    freopen("explore.in","r",stdin);//todo!
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--;y--;
        memset(b,0,sizeof b);
        for(int i=0;i<n;i++)
        {
            cin>>g[i];
        }
        js();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(b[i][j])ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
