#include<bits/stdc++.h>
using namespace std;
long long t[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(t,0,sizeof(t));
        long long n,x,maxx=0,minx=1000005,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            t[x]++;
            maxx=max(maxx,x);
            minx=min(minx,x);
        }
        for(long long i=minx;i<=maxx;i++)
        {
            if(t[i]>=2)ans+=(t[i]-1)*i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
