#include<bits/stdc++.h>
using namespace std;
bool flag[1001][1001];
int n,m,k,x,y,d,cnt;
char c[1001][1001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int kkk=1;kkk<=t;kkk++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        flag[x][y]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>c[i][j];
        }
        for(int i=1;i<=k;i++)
        {
            int tx,ty;
            if(d==0) tx=x,ty=y+1;
            else if(d==1) tx=x+1,ty=y;
            else if(d==2) tx=x,ty=y-1;
            else tx=x-1,ty=y;
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]=='.')
            {
                x=tx,y=ty;
                flag[x][y]=true;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(flag[i][j]) cnt++;
                flag[i][j]=false;
            }
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
