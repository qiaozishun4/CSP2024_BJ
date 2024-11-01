#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N],vis[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    queue<int> q;
    bool b=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        if(r[i]!=1 && r[i]!=2)  b=1;
        else
        {
            if(r[i]==1) cnt++;
        }
    }
    if(b==0)
    {
        if(cnt<n)   cnt=n-cnt;
        cout<<cnt;
        return 0;
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
        q.push(i);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int u=q.front();
        for(int j=u+1;j<=n;j++)
        {
            if(vis[j]==1)   continue;
            if(r[j]>r[u])
            {
                ans++;
                vis[j]=1;
                q.pop();
                break;
            }
        }
    }
    cout<<(n-ans);
    return 0;
}
