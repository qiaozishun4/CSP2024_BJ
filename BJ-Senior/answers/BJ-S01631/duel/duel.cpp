#include <bits/stdc++.h>
using namespace std;
int sum,a[100005],n,x,y,c[100005],g[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int min_=a[1],t=1;
    c[1]++;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>min_)
        {
            t++;
            c[t]++;
            g[t]++;
            min_=a[i];
        }
        else
        {
            c[t]++;
            g[t]++;
        }
    }
    for(int i=2;i<=t;i++)
    {
        for(int j=i-1;g[i]>0,j>=1;j--)
        {
            if(c[j]==0)
            {
                continue;
            }
            if(g[i]>c[j])
            {
                c[j]=0;
                g[j]=0;
                sum-=c[j];
                g[i]-=c[j];
            }
            else
            {
                c[j]-=g[i];
                g[j]-=g[i];
                sum-=g[i];
                g[i]=0;
            }
        }
    }
    cout<<sum;
    return 0;
}
