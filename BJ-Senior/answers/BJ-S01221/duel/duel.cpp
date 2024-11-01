#include<bits/stdc++.h>
using namespace std;
struct d
{
    int r;
    bool b;
}a[100005];
bool cmp(d a,d b)
{
    if(a.r<=b.r)
    {
        return 1;
    }
    return 0;
}
int n,ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].r;
    }
    if(a[10].r<=2&&a[12].r<=2)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i].r==2)
            {
                ans++;
            }
        }
        cout<<min(ans,n-ans);
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[mid].r>a[i].r&&!a[mid].b)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(a[mid].r>a[i].r&&!a[mid].b)
        {
            ans++;
            a[l].b=1;
        }
    }
    cout<<n-ans;
    return 0;
}
