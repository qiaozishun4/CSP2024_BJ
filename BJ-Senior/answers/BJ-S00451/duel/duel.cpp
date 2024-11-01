#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+10;
int n;
int a[maxn],cnt[maxn];
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    int rst=0;
    for(int i=1;i<=1e5;i++)
    {
        if(rst>=cnt[i]) continue;
        else rst=cnt[i];
    }
    cout<<rst<<endl;
	return 0;
}
