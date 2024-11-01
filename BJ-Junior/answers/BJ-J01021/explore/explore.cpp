#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,b,c;
char a[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int ii=0;ii<t;ii++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        b=0;
        c=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        a[x][y]=',';
        while(b!=k)
        {
            if(d==0)
            {
                if(a[x][y+1]!='x'&&y+1<=m)
                {
                    y++;
                    b++;
                    if(a[x][y]=='.')
                    {
                        c++;
                        a[x][y]=',';
                    }
                }
                else
                {
                    d=(d+1)%4;
                    b++;
                }
            }
            else if(d==1)
            {
                if(a[x+1][y]!='x'&&x+1<=n)
                {
                    x++;
                    b++;
                    if(a[x][y]=='.')
                    {
                        c++;
                        a[x][y]=',';
                    }
                }
                else
                {
                    d=(d+1)%4;
                    b++;
                }
            }
            else if(d==2)
            {
                if(a[x][y-1]!='x'&&y-1>=1)
                {
                    y--;
                    b++;
                    if(a[x][y]=='.')
                    {
                        c++;
                        a[x][y]=',';
                    }
                }
                else
                {
                    d=(d+1)%4;
                    b++;
                }
            }
            else if(d==3)
            {
                if(a[x-1][y]!='x'&&x-1>=1)
                {
                    x--;
                    b++;
                    if(a[x][y]=='.')
                    {
                        c++;
                        a[x][y]=',';
                    }
                }
                else
                {
                    d=(d+1)%4;
                    b++;
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}