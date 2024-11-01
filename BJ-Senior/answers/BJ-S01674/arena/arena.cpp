#include<bits/stdc++.h>
#define pb push_back
using namespace std;

string s[20];
int a[100005],c[100005],b[100005];
int ans[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int K=0,t=1;
    while(t<n)
    {
        t*=2;
        K++;
    }
    for(int i=1;i<=K;i++)
    {
        cin>>s[i];
    }
    int T;
    cin>>T;
    while(T--)
    {
        int x[6];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i]^x[i%4];
        }
    }
    for(int i=1,lim=0;i<=n;i*=2,lim++)
    {
        if(i==1)
        {
            ans[i]=1;
            continue;
        }
        for(int j=1;j<=n;j++)a[j]=b[j];
        for(int j=1;j<=lim;j++)
        {
            for(int k=1,r=0;k<=i;k+=(1<<j),r++)
            {
                // cout<<j<<' '<<k<<endl;
                // cout<<k<<' '<<k+(1<<j-1)<<endl;
                if(s[j][r]=='1')
                {
                    if(a[k+(1<<(j-1))]>=r)swap(a[k],a[k+(1<<(j-1))]);
                }
                else
                {
                    if(a[k]<r)swap(a[k],a[k+(1<<(j-1))]);
                }
            }
        }
        ans[i]=a[1];
    }
    int ret=0;
    for(int i=1;i<=m;i++)
    {
        ret=ret^ans[c[i]];
    }
    cout<<ret;
    return 0;
}