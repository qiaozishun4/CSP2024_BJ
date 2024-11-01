#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,ans1=0,anssec,ans2=0;

struct car{
    double d,v0,v1,a;
    double overs;
} cars[100005];

struct detector{
    int p;
    int detectedcount=0;
    bool enabled=1;
} dets[100005];

void reset()
{
    ans1=0;
    for(int i=0;i<100005;i++)
    {
        dets[i].detectedcount=0;
    }
}

void monit()
{
    for(int l=0;l<n;l++)
    {
        for(int i=cars[l].overs+cars[l].d;i<L;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dets[j].p==i&&dets[j].enabled)
                {
                    dets[j].detectedcount++;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        ans1=max(ans1,dets[i].detectedcount);
    }
}

void solve(int x)
{
    if(x>ans2)
    {
        ans2=x;
    }
    for(int i=0;i<m;i++)
    {
        if(dets[i].enabled)
        {
            dets[i].enabled=0;
            reset();
            monit();
            if(ans1==anssec)
            {
                solve(x+1);
            }
            dets[i].enabled=1;
        }
    }
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++)
        {
            cin>>cars[i].d>>cars[i].v0>>cars[i].a;
            cars[i].overs=cars[i].a!=0?(V*V-cars[i].v0*cars[i].v0)/(2*cars[i].a):1e9;
        }
        for(int i=0;i<m;i++)
        {
            cin>>dets[i].p;
        }
        monit();
        anssec=ans1;
        cout<<anssec<<" ";
        solve(0);
        cout<<ans2-1<<endl;
    }
    return 0;
}
