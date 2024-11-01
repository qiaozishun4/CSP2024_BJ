#include <bits/stdc++.h>
using namespace std;
int a[100005],cnt[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int k=0;
    for(int i=0;i<=100000;i++) k=cnt[i]+max(0,k-cnt[i]);
    cout<<k<<endl;
    return 0;
}
