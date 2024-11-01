#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N],cnt[N],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
        cnt[r[i]]++;
    }
    for(int i=1;i<=N;i++){
        if(cnt[i]>ans)
        {
            ans+=cnt[i]-ans;
        }
    }
    cout<<ans;
    return 0;
}
