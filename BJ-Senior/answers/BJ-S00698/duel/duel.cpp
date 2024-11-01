#include<bits/stdc++.h>
using namespace std;

int n,ans;
int r[100005],vis[100005]={0};

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    int i=1,j=1;
    while(i<=n&&j<=n)
    {
        while(r[i]==r[j])j++;
        if(j<=n&&r[i]<r[j]&&!vis[i])
        {
            ans--;
            j++;
            vis[i]=1;
        }
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
