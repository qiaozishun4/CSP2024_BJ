#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005],les[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) les[i]=i-1;
        else les[i]=les[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(les[i]-ans>0) ans++;
    }
    cout<<n-ans;
    return 0;
}
