#include<bits/stdc++.h>
using namespace std;
long long n,a[1010100],b[1010100];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,koth=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            koth+=cnt;
            cnt=0;
        }
        cnt++;
        if(koth>0) koth--,ans++;
    }
    cout<<n-ans;
    return 0;
}
