#include<bits/stdc++.h>
using namespace std;
int a[100010],dis[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int maxn=0,maxc;
        if(dis[i]) continue;
        for(int j=1;j<=n;j++)
        {
            if(a[i]>a[j]&&!dis[j])
            {
                maxn=a[i]-a[j];
                maxc=j;
            }
        }
        dis[maxc]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!dis[i]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
