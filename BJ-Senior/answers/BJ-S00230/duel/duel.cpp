#include<bits/stdc++.h>
using namespace std;
int n,ans,x;
struct node
{
    int s,cnt;
}r[100010];
bool cmp(node a,node b)
{
    return a.s<b.s;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=1;i<=100000;i++) r[i].s=1e7;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        r[x].s=x;
        r[x].cnt++;
    }
    sort(r+1,r+100000+1,cmp);
    ans=r[1].cnt;
    for(int i=2;i<=n;i++)
    {
        ans-=r[i].cnt;
        ans=max(0,ans);
        ans+=r[i].cnt;
    }
    cout<<ans<<endl;
    return 0;
}
