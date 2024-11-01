#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt=1;
int a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            string b;
            cin>>b;
            for(int t=1;t<=m;t++){
                if(b[t-1]=='.')
                {
                    a[j][t]=1;
                }
                else{
                    a[j][t]=0;
                }
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(a[x][y+1]==1)
                {
                    cnt++;
                    y++;
                }
                else
                {
                    d=((d+1)%4);
                    continue;
                }
            }
            if(d==1)
            {
                if(a[x+1][y]==1)
                {
                    cnt++;
                    x++;
                }
                else
                {
                    d=((d+1)%4);
                    continue;
                }
            }
            if(d==2)
            {
                if(a[x][y-1]==1)
                {
                    cnt++;
                    y--;
                }
                else
                {
                    d=((d+1)%4);
                    continue;
                }
            }
            if(d==3)
            {
                if(a[x-1][y]==1)
                {
                    cnt++;
                    x--;
                }
                else
                {
                    d=((d+1)%4);
                    continue;
                }
            }
        }
        cout<<cnt<<'\n';
        cnt=0;
    }
    return 0;
}
