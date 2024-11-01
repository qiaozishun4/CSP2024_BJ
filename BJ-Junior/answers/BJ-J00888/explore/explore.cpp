#include<bits/stdc++.h>
using namespace std;
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
char a[1010][1010];
bool temp[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        int ans=1;
        temp[x][y]=true;
        while(k--)
        {
            int dx=x+mx[d];
            int dy=y+my[d];
            if(dx<=n&&dx>=1&&dy<=m&&dy>=1&&a[dx][dy]=='.')
            {
                x=dx;
                y=dy;
                if(!temp[x][y])
                {
                    temp[x][y]=true;
                    ans++;
                }
            }
            else
                d=(d+1)%4;
        }
        cout<<ans<<endl;
        memset(temp,0,sizeof(temp));
    }
    return 0;
}
