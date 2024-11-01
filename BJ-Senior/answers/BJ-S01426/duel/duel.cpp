#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e5+5;
int n,x;
int a[maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    _for(i,1,n)
    {
        cin>>x;
        a[x]++;
    }
    bool ok=1;
    int ans=0,now=0;
    _for(i,1,maxn)
    {
        if(!a[i]) continue;
        if(ok)
        {
            now=a[i];
            ok=0;
            continue;
        }
        if(a[i]>=now) ans+=now,now=a[i];
        else ans+=a[i];
    }
    cout<<n-ans<<endl;
    return 0;
}
