#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("explore","r",stdin);
freopen("explore","w",stdout);
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int n,m,s;
    cin>>n>>m>>s;
    int x,y,e;
    cin>>x>>y>>e;
    char a[n][m];
    int b[n][m];
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[i][j]=0;
        }
    }
    int u=1;
    for(int j=0;j<s;j++)
    {
        if(e==0)
        {
            if(y+1<m&&a[x][y+1]!='x')
                y++;b[x][y]=1;
            else
                e++;continue;
        }
        if(e==1)
        {
            if(x+1<n&&a[x+1][y]!='x')
                x++;b[x][y]=1;
            else
                e++;continue;
        }
        if(e==2)
        {
            if(y-1>=0&&a[x][y-1]!='x')
                y--;b[x][y]=1;
            else
                e++;continue;
        }
        if(e==3)
        {
            if(x-1>=0&&a[x-1][y]!='x')
                x--;b[x][y]=1;
            else
                e++;continue;
        }
    }
    int u=1;
    for(int j=0;j<n;j++)
    {
        for(int l=0;l<m;l++)
        {
            if(b[i][j]==1)
            u++;
        }
    }
    cout<<u<<endl;
}
return 0;
}