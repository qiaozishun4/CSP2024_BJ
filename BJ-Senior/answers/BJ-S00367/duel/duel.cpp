#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],f[200001],ans;
bool vis[200001],atc[200001];
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
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]<a[j]&&atc[j]==false)
            {
                vis[i]=true;
                atc[j]=true;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false) ans++;
    }
    cout<<ans;
    return 0;
}
