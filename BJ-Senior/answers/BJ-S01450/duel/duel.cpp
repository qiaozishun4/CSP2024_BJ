#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,ans=n;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>a[l])ans--,l++;
    }
    cout<<ans<<endl;
    return 0;
}
