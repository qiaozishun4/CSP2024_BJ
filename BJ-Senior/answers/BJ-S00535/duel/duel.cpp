#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100100],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;ans=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i++)
    {
        if(a[i]>a[j]) j++,ans--;
    }
    cout<<ans;
    return 0;
}
