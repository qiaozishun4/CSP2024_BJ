#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f[100005],sum[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bool fl=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=2)
        {
            fl=1;
        }
    }
    sort(a+1,a+n+1);

    int cnt=0,s=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            s=1;
            f[++cnt]=s;
        }
        else
        {
            f[cnt]=++s;
        }
    }
    if(cnt==1)
    {
        cout<<f[1];
        return 0;
    }
    if(fl==0)
    {
        if(f[2]>=f[1])
        {
            cout<<f[2]-f[1];
        }
        else
        {
            cout<<f[1]-f[2];
        }
        return 0;
    }
    int y=0;
    for(int i=2;i<=cnt;i++)
    {
        if(f[i]>=f[i-1])
        {
            f[i-1]=0;
        }
        else
        {
            int x=0;
            for(int j=i;j<=n;j++)
            {
                if(x+f[j]>=f[i-1])
                {
                    x+=f[j];
                    f[j]=x;
                    y=j;
                    j=n+1;
                }
                else
                {
                    f[j]=0;
                }
            }
            if(x<f[i-1])
            {
                cout<<f[i-1];
                return 0;
            }
            else
            {
                f[i-1]=0;
                i=y;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        ans+=f[i];
    }
    cout<<ans;
    return 0;
}
//lz