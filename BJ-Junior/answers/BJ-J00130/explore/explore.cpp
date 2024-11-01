#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,d,x2,y2,num;
char s[1001][1001],a;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        num=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>s[j][k];
            }
        }
        for(int j=1;j<=k;j++)
        {
            s[x][y]='y';
            if(d==0)
            {
                a=s[x][y+1];
                x2=x;
                y2=y+1;
            }
            if(d==1)
            {
                a=s[x+1][y];
                x2=x+1;
                y2=y;
            }
            if(d==2)
            {
                a=s[x][y-1];
                x2=x;
                y2=y-1;
            }
            if(d==3)
            {
                a=s[x-1][y];
                x2=x-1;
                y2=y;
            }
            if(a!='.'&&a!='y')
            {
                d=(d+1)%4;
            }
            else
            {
                x=x2;
                y=y2;
                if(a!='y')
                {
                    num++;
                }
            }
        }
        cout<<num<<"\n";
    }
}
