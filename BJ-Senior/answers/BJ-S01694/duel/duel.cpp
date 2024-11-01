#include<bits/stdc++.h>
using namespace std;
int a[100005],n,r[100005],cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=n;i++)
    {
        if(a[r[i]]==1) cnt++;
        else a[r[i]]=1;
    }
    cout<<cnt;
    return 0;
}