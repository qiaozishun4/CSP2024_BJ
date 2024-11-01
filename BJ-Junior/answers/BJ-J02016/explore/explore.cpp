#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,c;
char a[1010][1010];
bool f[1010][1010];
void dfs(int x,int y)
{
    if(k==-1)return ;
    if(!f[x][y])
    {
        c++;
        f[x][y]=true;
    }
    if(d==0 && y+1<=m && a[x][y+1]!='x')
    {
        k--;
        dfs(x,y+1);
    }
    else if(d==1 && x+1<=n && a[x+1][y]!='x')
    {
        k--;
        dfs(x+1,y);
    }
    else if(d==2 && y-1>=1 && a[x][y-1]!='x')
    {
        k--;
        dfs(x,y-1);
    }
    else if(d==3 && x-1>=1 && a[x-1][y]!='x')
    {
        k--;
        dfs(x-1,y);
    }
    else
    {
        k--;
        d=(d+1)%4;
        dfs(x,y);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    int i,j,x,y;
    while(t--)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        c=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(x,y);
        cout<<c<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
