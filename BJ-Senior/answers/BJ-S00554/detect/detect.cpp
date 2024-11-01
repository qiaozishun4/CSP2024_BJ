#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int d[10001],v[10001],a[10001],x[10001],y[10000001];
bool f[10000001];
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,V;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n>>m>>l>>V;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>x[i];
            y[x[i]]=0;
            f[x[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            int sd=v[i],cc=0,g=0;
            bool flag=1;
            for(int j=d[i];j<=l;j++)
            {
                if(sd==0) break;
                if(f[j]==1)
                {
                    if(sd>V)
                    {
                        cc++;
                        if(cc==1) g=j;
                        else
                        {
                            y[g]--;
                            g=j;
                        }
                        if(flag)
                        {
                            cnt++;
                            flag=0;
                        }
                        y[j]++;
                    }
                }
                sd+=a[i];
            }
        }
        int c=0;
        for(int i=1;i<=m;i++)
        {
            if(y[x[i]]<=0)
            {
                c++;
            }
        }
        cout<<cnt<<" "<<c<<"\n";
    }
    return 0;
}