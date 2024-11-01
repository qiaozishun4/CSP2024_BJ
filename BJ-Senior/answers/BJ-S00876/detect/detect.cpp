#include<bits/stdc++.h>
using namespace std;
int t,d[100010],a[100010],v[100010],p[100010],n,m,L,V,sum=0;
bool check(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(p[i]>=d[i]&&p[i]<=L)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]>V&&check(i))
            {
                sum++;
            }
        }
        cout<<sum<<' '<<m-1;
    }
    return 0;
}
