#include<bits/stdc++.h>
using namespace std;
char a[1020][1020];
int b[1020][1020];
int t,n,m,k,x,y,d;
int c=0,z,i,j;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(z=1;z<=t;z++)
    {
        c=0;
        cin>>n>>m>>k;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                b[i][j]=0;
        cin>>x>>y>>d;
        x--;
        y--;
        b[x][y]=1;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>a[i][j];
        for(i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(y==m-1)
                {
                    d=1;
                    continue;
                }
                if(a[x][y+1]=='x')
                {
                    d=1;
                    continue;
                }
                y++;
                b[x][y]=1;
            }
            if(d==1)
            {
                if(x==n-1)
                {
                    d=2;
                    continue;
                }
                if(a[x+1][y]=='x')
                {
                    d=2;
                    continue;
                }
                x++;
                b[x][y]=1;
            }
            if(d==2)
            {
                if(y==0)
                {
                    d=3;
                    continue;
                }
                if(a[x][y-1]=='x')
                {
                    d=3;
                    continue;
                }
                y--;
                b[x][y]=1;
            }
            if(d==3)
            {
                if(x==0)
                {
                    d=0;
                    continue;
                }
                if(a[x-1][y]=='x')
                {
                    d=0;
                    continue;
                }
                x--;
                b[x][y]=1;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(b[i][j]==1)
                    c++;
        cout<<c<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}