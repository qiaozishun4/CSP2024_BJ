#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int r[1000005];
    int vis[1000005]={0};
    int live=n;
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    sort(r,r+n);
    for(int i=0;i<n-1;i++)
    {
        int t=i;
        while(vis[t]==1)
        {
            t--;
        }
        if(r[i+1]>r[t])
        {
            vis[i]=1;
            live--;
        }
        vis[i+1]=1;
    }
    cout<<live;
    return 0;
}
