#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+5;
int a[N],n,num[N],ans,mxnum;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    faster;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        num[a[i]]++;
        mxnum=max(mxnum,a[i]);
    }
    for(int i=1;i<=mxnum;i++)
    {
        if(num[i])
        {
            ans=max(0,ans-num[i]);
            ans+=num[i];
        }
    }
    cout << ans;
    return 0;
}