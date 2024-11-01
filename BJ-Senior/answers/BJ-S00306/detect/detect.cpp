#include<bits/stdc++.h>
using namespace std;
int n,m,l,vmax;
int d[100005];
bool vis[100005];
struct car
{
    int d,v,a;
    double dt;
    void read()
    {
        cin>>d>>v>>a;
        if(a!=0) dt=d+(vmax*vmax-v*v)/(2*a);
    }
}c[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>l>>vmax;
        for(int i = 1; i<=n; i++)
        {
            c[i].read();
        }
        for(int i = 1; i<=m; i++)
        {
            cin>>d[i];
        }
        sort(d+1,d+m+1);
        int cnt=0;
        for(int i = 1; i<=n; i++)
        {
            if(c[i].a==0)
            {
                if(c[i].v<=vmax) continue;
                int p=lower_bound(d+1,d+n+1,c[i].d)-d;
                //cout<<i<<" "<<d[p]<<' '<<c[i].d<<endl;
                if(p<=n)
                {
                    cnt++;
                    vis[p]=1;
                    //cout<<i<<endl;
                }
            }
            else if(c[i].a<0)
            {
                int p=lower_bound(d+1,d+n+1,c[i].d)-d;
                if(d[p]<c[i].dt)
                {
                    cnt++;
                    vis[p]=1;
                    //cout<<i<<" "<<c[i].dt<<endl;
                }
            }
            else
            {
                int p=upper_bound(d+1,d+n+1,c[i].dt)-d;
                if(p<=n)
                {
                    cnt++;
                    vis[p]=1;
                    //cout<<i<<endl;
                }
            }
        }
        int sum=0;
        for(int i = 1; i<=m; i++)
        {
            if(vis[i]==0) sum++;
        }
        cout<<cnt<<" "<<sum<<endl;
    }
    return 0;
}
