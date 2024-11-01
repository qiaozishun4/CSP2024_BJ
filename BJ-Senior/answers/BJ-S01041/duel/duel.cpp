#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,r[MAXN],cnt[MAXN],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        cnt[r[i]]++;
    }
    for(int i=1;i<=MAXN;i++)
        if(cnt[i]>ans)
            ans=cnt[i];
    cout<<ans;
    return 0;
}
