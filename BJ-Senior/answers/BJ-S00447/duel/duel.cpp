#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[l]) ans++,l++;
    }
    cout<<n-ans<<'\n';
}