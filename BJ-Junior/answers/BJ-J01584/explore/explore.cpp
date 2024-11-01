#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        map<long long,bool> p;
        int x,y,d,nx,ny,ans=0;
        cin>>x>>y>>d;
        string pp[3000];
        for(int j=1;j<=n;j++)
        {
            cin>>pp[j];
            pp[j]="0"+pp[j];
        }
        p[(x*1e4)+y]++;
        ans++;
        for(int j=0;j<k;j++)
        {
            if(d%2==1)
            {
                nx=x+(2-d);
                ny=y;
            }
            else
            {
                ny=y+(1-d);
                nx=x;
            }
            if(((nx>=1&&ny>=1)&&(nx<=n&&ny<=m))&&pp[nx][ny]=='.')
            {
                x=nx;
                y=ny;
                if(p[(x*1e4)+y]==0)
                {
                    p[(x*1e4)+y]++;
                    ans++;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
