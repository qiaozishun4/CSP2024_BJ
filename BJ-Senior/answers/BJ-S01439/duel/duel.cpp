#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int l;
int ans;
int a[maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    l=1;
    for(int i=2;i<=n;i++)
        if(a[l]<a[i])
        {
            ans++;
            l++;
        }
    cout<<n-ans;
    return 0;
}
