#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0,wz=1;
    for(int i=1; i<=n; ++i)
    {
        while(wz<=n && a[wz]<=a[i]) ++wz;
        if(wz<=n) ++ans,++wz;
    }
    cout<<n-ans;
    return 0;
}
