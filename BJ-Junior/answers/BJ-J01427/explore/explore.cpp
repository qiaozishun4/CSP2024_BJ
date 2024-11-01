#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        int n,m,k,x,y,d;
        char dt[1005][1005]={0};
        bool goes[1005][1005]={0};
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>dt[i][j];
            }
        }
        int ans=1;
        while(1)
        {
            goes[x][y]=1;
            if(k==0)
            {
                break;
            }
            if(d==0)
            {
                if(y+1>=1 && y+1<=m && dt[x][y+1]=='.')
                {
                    k--;
                    if(!goes[x][y+1])
                    {
                        goes[x][y+1]=1;
                        ans++;
                    }
                    x=x;
                    y=y+1;
                }
                else
                {
                    d=(d+1)%4;
                    k--;
                }
            }
            if(d==1)
            {
                if(x+1>=1 && x+1<=n && dt[x+1][y]=='.')
                {
                    k--;
                    if(!goes[x+1][y])
                    {
                        goes[x+1][y]=1;
                        ans++;
                    }
                    x=x+1;
                    y=y;
                }
                else
                {
                    d=(d+1)%4;
                    k--;
                }
            }
            if(d==2)
            {
                if(y-1>=1 && y-1<=m && dt[x][y-1]=='.')
                {
                    k--;
                    if(!goes[x][y-1])
                    {
                        goes[x][y-1]=1;
                        ans++;
                    }
                    x=x;
                    y=y-1;

                }
                else
                {
                    d=(d+1)%4;
                    k--;
                }
            }
            if(d==3)
            {
                if(x-1>=1 && x-1<=n && dt[x-1][y]=='.')
                {
                    if(!goes[x-1][y])
                    {
                        goes[x-1][y]=1;
                        ans++;
                    }
                    x=x-1;
                    y=y;
                }
                else
                {
                    d=(d+1)%4;
                    k--;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
