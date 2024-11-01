#include <bits/stdc++.h>
using namespace std;
int n,ans,g[101010];
int gjcs,ch,bj[100100],T=1,t=1;
struct dg
{
    int r;
    bool gj,sm;
}a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    gjcs=n;
    ch=n;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
    }
    sort(g+1,g+1+n);
    for(int i=1;i<=n;i++)
    {
        if(g[i]!=g[i-1])
        {
            bj[T++]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        a[i].r=g[i];
        a[i].gj=1;
        a[i].sm=1;
    }
    for(int i=1;i<=n;i++)
    {
//        for(int j=i+1;j<=n;j++)
//        {
            if(a[i].r>a[i-1].r&&i!=1||bj[t+1]==bj[t+2])
            {
                t++;//cout<<i<<' ';
            }
            if(a[bj[t+1]].r>a[i].r&&a[bj[t+1]].gj)
            {
                gjcs--;
                ch--;
                //cout<<a[bj[t+1]].r<<' '<<a[i].r<<' '<<bj[t+1]<<';';
                a[bj[t+1]].gj=0;
                a[i].sm=0;
            }
            bj[t+1]++;
//        }
    }
    cout<<ch;
    return 0;
}
