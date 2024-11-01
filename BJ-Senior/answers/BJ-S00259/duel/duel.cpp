#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=1000000+5;
int n,a[n_MAX];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    For(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int j=1;
    For(i,1,n)
    {
        if(a[i]>a[j]) ++j;
    }
    cout<<(n-j+1)<<'\n';
    return 0;
}