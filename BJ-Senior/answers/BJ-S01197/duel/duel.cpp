#include<bits/stdc++.h>
using namespace std;
int a[100005];
int vis1[100005];
int vis2[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(vis1[j])
            {
                continue;
            }
            if(vis2[i])
            {
                continue;
            }
            if(a[i]>a[j])
            {
                vis1[j]=1;
                vis2[i]=1;
                cnt--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
