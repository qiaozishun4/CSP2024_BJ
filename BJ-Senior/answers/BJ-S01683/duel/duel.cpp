#include<bits/stdc++.h>
using namespace std;
int n;
struct p
{
    int val,num,pre,nex;
}a[100005];
bool vis[100005];
long long ans;
bool cmp(p a,p b)
{
    return a.val<b.val;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
    }
    sort(a+1,a+1+n,cmp);
    if(a[1].val==a[n].val)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        a[i].pre=i-1;
        a[i].nex=i+1;
    }
    a[0].nex=1;
    a[n+1].pre=n;
    for(int i=2;i!=n+1;i=a[i].nex)
    {
        for(int j=a[0].nex;j!=i;j=a[j].nex)
        {
            if(a[j].val<a[i].val&&vis[j]==0)
            {
                vis[j]=1;
                ans--;
                int l=a[j].pre,r=a[j].nex;
                a[l].nex=r;
                a[r].pre=l;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
