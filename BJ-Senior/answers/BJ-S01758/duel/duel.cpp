#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int hv[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)scanf("%d",&x),hv[x]++;
    int ans=0;
    for(int i=1;i<=1e5;i++)ans=max(ans,hv[i]);
    cout<<ans<<endl;
    return 0;
}
