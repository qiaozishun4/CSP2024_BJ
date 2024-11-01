#include<bits/stdc++.h>
using namespace std;
int fds(int sd)
{
    int n,m,k,x,y,d;
    char ditu[100][100],di[100][100];

    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) cin>>ditu[i][j];
    }
    for (int i=0;i<k;i++)
    {
        di[x][y]='1';
        if (d==1)
        {
            if (x+1<=n && ditu[x+1][y]!='x') x+=1;
            else d=(d+1)%4;
        }
        if (d==2)
        {
            if (y-1>=1 && ditu[x][y-1]!='x') y-=1;
            else d=(d+1)%4;
        }
        if (d==3)
        {
            if (x-1>=1 && ditu[x-1][y]!='x') x-=1;
            else d=(d+1)%4;
        }
        if (d==0)
        {
            if (y+1<=m && ditu[x][y+1]!='x') y+=1;
            else d=(d+1)%4;
        }
    }
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (di[i][j]=='1')
            {
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
int main()
{
    freopen("/home/cspj/test12/eqeqwqwewq/explore.in","r",stdin);
    freopen("/home/cspj/test12/eqeqwqwewq/explore.out","w",stdout);
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        fds(1);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
