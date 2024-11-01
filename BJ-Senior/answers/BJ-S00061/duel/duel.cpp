#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,j=2;j<=n;j++)
    {
        if(a[i]<a[j])
        {
            b[i]=1;
            i++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
