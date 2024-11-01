#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n,i,j,ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]<a[j]&&b[j]==0)
            {
                b[i]=1;
                b[j]=2;
                break;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0||b[i]==2) ans++;
    }
    cout<<ans;
    return 0;
}

/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
