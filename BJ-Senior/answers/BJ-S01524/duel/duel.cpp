#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],n,x,ans,cnt[maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];cnt[a[i]]++;}
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        x++;
        if(a[i]!=a[i-1]) break;
    }
    for(int i=1;i<=100000;i++)
        if(cnt[i]>x) ans+=cnt[i]-x;
    cout<<ans+x;
    return 0;
}