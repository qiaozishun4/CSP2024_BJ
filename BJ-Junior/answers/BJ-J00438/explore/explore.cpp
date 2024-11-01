#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,s;
bool ans[1007][1007];
char mp[1007][1007];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        memset(ans,0,sizeof(ans));
        s=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
           
        ans[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(y+1>m || mp[x][y+1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    y++;
                    ans[x][y]=1;
                }
            }
            else if(d==1)
            {
                if(x+1>n || mp[x+1][y]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x++;
                    ans[x][y]=1;
                }
            }
            else if(d==2)
            {
                if(y-1<1 || mp[x][y-1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    y--;
                    ans[x][y]=1;
                }
            }
            else if(d==3)
            {
                if(x-1<1 || mp[x-1][y]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x--;
                    ans[x][y]=1;
                } 
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ans[i][j]==1)
                {
                    s++;                    
                }
            }     
        } 
        cout<<s<<endl;
    }
    return 0;
}