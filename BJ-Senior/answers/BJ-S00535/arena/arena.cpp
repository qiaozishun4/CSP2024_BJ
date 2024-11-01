#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100100];
ll c[100100],sum=0;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
