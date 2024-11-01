#include <bits/stdc++.h>
#define ll long long
using namespace std;
int r[100005];
bool vis[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool ismin2=1;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        if(r[i]==1)
        {
            cnt1++;
        }
        if(r[i]==2)
        {
            cnt2++;
        }
        if(r[i]>2)
        {
            ismin2=0;
        }
    }
    if(ismin2)
    {
        cout<<n-min(cnt1,cnt2);
        return 0;
    }
    sort(r+1,r+n+1);
    int ans=0,cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[cnt]&&r[cnt]<r[i])
        {
            vis[cnt]=1;
            ans++;
            cnt++;
        }
    }
    cout<<n-ans;
    return 0;
}
