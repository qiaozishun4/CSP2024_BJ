#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    freopen("duel.in","r",stdin);freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1,x;i<=n;i++) cin>>x,cnt[x]++;
    int pre=0;for(int i=1;i<N;i++) if(cnt[i]&&cnt[i]>ans) ans=cnt[i];
    cout<<ans;
    return 0;
}