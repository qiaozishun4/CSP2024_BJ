#include <bits/stdc++.h>
using namespace std;
int nnext[4][2]={0,1,1,0,0,-1,-1,0};
char mm[10000][10000];
bool book[10000][10000];
int t;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        memset(book,false,sizeof(book));
        int n,m,k,x,y,d;
        long long ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>mm[i][j];
        }
        for(int i=1;i<=k;i++)
        {
            int nx=x+nnext[d][0],ny=y+nnext[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mm[nx][ny]=='.')
            {
                if(!book[nx][ny])
                {
                    ans++;
                }
                book[nx][ny]=true;
                x=nx;
                y=ny;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
