#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
struct r
{
    int d;
    int g;
}a[100001];
int h(r q,r w)
{
    return q.d>w.d;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        a[m].g++;
        a[m].d=m;
        ma=max(ma,m);
    }
    sort(a+1,a+ma+1,h);
    for(int i=ma;i>=1;i--)
    {
        n-=min(a[i+1].g,a[i].g);
        a[i].g+=max(0,a[i+1].g-a[i].g);
    }
    cout<<n;
    return 0;
}