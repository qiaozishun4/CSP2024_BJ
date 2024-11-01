#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=1000000+5;
int n,m,a[n_MAX];
long long F[n_MAX];
inline void chk_max(long long &x,const long long y)
{
    ((y>x)&&(x=y));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T; cin>>T;
    while(T--)
    {
        long long cur=0,tag=0;
        cin>>n,m=0;
        For(i,1,n) cin>>a[i],m=max(m,a[i]);
        For(i,1,m) F[i]=(-(1LL<<60));
        For(i,2,n)
        {
            long long val=cur;
            chk_max(val,F[a[i]]+a[i]+tag);
            if(a[i]==a[i-1]) cur+=a[i],tag+=a[i];
            chk_max(cur,val);
            chk_max(F[a[i-1]],val-tag);
        }
        cout<<cur<<'\n';
    }
    return 0;
}