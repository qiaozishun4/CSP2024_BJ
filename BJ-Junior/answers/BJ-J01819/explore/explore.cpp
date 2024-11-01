#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,xt,yt,dt,ans=0;
        cin>>n>>m>>k;
        int tu[1005][1005];
        cin>>xt>>yt>>dt;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='.')
                    tu[i][j]=0;
                else
                    tu[i][j]=-1;
            }
        }
        tu[xt][yt]=1;
        ans++;
        for(int i=1;i<=k;i++)
        {
            if(dt==0)
            {
                if(yt+1>m||tu[xt][yt+1]==-1)
                    dt=1;
                else
                {
                    yt+=1;
                    if(tu[xt][yt]==0)
                    {
                        tu[xt][yt]=1;
                        ans++;
                    }
                }
            }
            else if(dt==1)
            {
                if(xt+1>n||tu[xt+1][yt]==-1)
                    dt=2;
                else
                {
                    xt+=1;
                    if(tu[xt][yt]==0)
                    {
                        tu[xt][yt]=1;
                        ans++;
                    }
                }
            }

            else if(dt==2)
            {
                if(yt-1<1||tu[xt][yt-1]==-1)
                    dt=3;
                else
                {
                    yt-=1;
                    if(tu[xt][yt]==0)
                    {
                        tu[xt][yt]=1;
                        ans++;
                    }
                }
            }
            else if(dt==3)
            {
                if(xt-1<1||tu[xt-1][yt]==-1)
                    dt=0;
                else
                {
                    xt-=1;
                    if(tu[xt][yt]==0)
                    {
                        tu[xt][yt]=1;
                        ans++;
                    }
                }
            }
            //cout<<i<<":"<<xt<<" "<<yt<<" "<<dt<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
