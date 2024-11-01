#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
int n,m,k,xx,yy,dd,book[1005][1005];
int dfs(int x,int y,int d,int step,int ans)
{
    if((d==0&&y+1>m)||(d==1&&x+1>n)||(d==2&&y-1<=0)||(d==3&&x-1<=0))
    {
        if(step+1==k)
        {
            return ans;
        }
        else
        {
            dfs(x,y,(d+1)%4,step+1,ans);
        }
    }
    else if((d==0&&c[x][y+1]=='x')||(d==1&&c[x+1][y]=='x')||(d==2&&c[x][y-1]=='x')||(d==3&&c[x-1][y]=='x'))
    {
        if(step+1==k)
        {
            return ans;
        }
        else
        {
            dfs(x,y,(d+1)%4,step+1,ans);
        }
    }
    else
    {
        if(step+1==k)
        {
            return ans;
        }
        else if(d==0)
        {
            if(book[x][y+1]==true)
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    dfs(x,y+1,d,step+1,ans);
                }
            }
            else
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    book[x][y+1]=true;
                    dfs(x,y+1,d,step+1,ans+1);
                }
            }
        }
        else if(d==1)
        {
            if(book[x+1][y]==true)
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    dfs(x+1,y,d,step+1,ans);
                }

            }
            else
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    book[x+1][y]=true;
                    dfs(x+1,y,d,step+1,ans+1);
                }

            }
        }
        else if(d==2)
        {
            if(book[x][y-1]==true)
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    dfs(x,y-1,d,step+1,ans);
                }
            }
            else
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    book[x][y-1]=true;
                    dfs(x,y-1,d,step+1,ans+1);
                }

            }

        }
        else if(d==3)
        {
            if(book[x-1][y]==true)
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    dfs(x-1,y,d,step+1,ans);
                }
            }
            else
            {
                if(step+1==k)
                {
                    return ans;
                }
                else
                {
                    book[x-1][y]=true;
                    dfs(x-1,y,d,step+1,ans+1);
                }

            }

        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        memset(book,false,sizeof(book));
        book[xx][yy]=true;
        cout<<dfs(xx,yy,dd,-1,1)<<'\n';
    }
    return 0;
}
