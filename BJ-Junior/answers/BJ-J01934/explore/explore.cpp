#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t>0)
    {
        int n,m,k,x,y,d,ans=0;
        string fr[1010];
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<n;i++)
            cin>>fr[i];
        fr[x-1][y-1]='-';
        for(int i=0;i<k;i++)
        {
            switch(d)
            {
                case 0:
                    if((1<=y+1&&y+1<=m)&&fr[x-1][y]!='x')
                    {
                        fr[x-1][y]='-';
                        y=y+1;
                    }
                    else
                    {
                        d=(d+1)%4;
                    }
                    break;
                case 1:
                    if((1<=x+1&&x+1<=n)&&fr[x][y-1]!='x')
                    {
                        fr[x][y-1]='-';
                        x=x+1;
                    }
                    else
                    {
                        d=(d+1)%4;
                    }
                    break;
                case 2:
                    if((1<=y-1&&y-1<=m)&&fr[x-1][y-2]!='x')
                    {
                        fr[x-1][y-2]='-';
                        y=y-1;
                    }
                    else
                    {
                        d=(d+1)%4;
                    }
                    break;
                case 3:
                    if((1<=x-1&&x-1<=n)&&fr[x-2][y-1]!='x')
                    {
                        fr[x-2][y-1]='-';
                        x=x-1;
                    }
                    else
                    {
                        d=(d+1)%4;
                    }
                    break;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(fr[i][j]=='-')ans++;
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
