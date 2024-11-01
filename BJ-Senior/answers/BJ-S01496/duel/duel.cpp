#include<bits/stdc++.h>
using namespace std;
int n,r[100005],cnt,sum,ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans = n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
    {
        if(r[i]!=r[i-1])
        {
            sum = i-1;
        }
        if(cnt<sum)
        {
            ans--;
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}