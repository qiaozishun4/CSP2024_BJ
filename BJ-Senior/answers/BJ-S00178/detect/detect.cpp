#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int d[N],v[N],a[N],c[N],vis[N],vis2[N],T,ans1,ans2,vis3[N],vis4[N];

int qs[N],js[N];

int main()
{
    freopen("detect.in","r",stdin);freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];

        }
        for(int i=1;i<=m;i++)
        {
            cin>>c[i];

        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[j]<d[i])continue;
                int k=v[i]*v[i]+2*a[i]*(c[j]-d[i]);
                if(k<=0)break;
                cout<<k<<"  ";
                if(k>V*V)
                {
                    if(vis[i]==0)
                    {
                        ans1++;
                        qs[i]=j;
                    }
                    else if(vis[i]==1)
                    {
                        js[i]=j;
                    }
                    vis[i]=1;

                }
            }
            if(vis[i]==1&&js==0)js=m;
            cout<<"\n";

        }
        cout<<ans1<<" "<<n-3<<"\n";
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=m;i++)vis2[i]=0;
        ans1=ans2=0;
    }
    return 0;
}
