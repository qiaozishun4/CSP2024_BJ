#include<bits/stdc++.h>
using namespace std;
int n;
int a[101];
int t[101];
int maxc=0;
void dfs(int step,int lr,int lb)
{
    if(step==n+1)
    {
        int sum=0;
        for(int i=2;i<=n;i++)
        {
            if(t[i]==-1) continue;
            if(a[i]==a[t[i]]) sum+=a[i];
        }
        maxc=max(maxc,sum);
        return;
    }
    t[step]=lr;
    dfs(step+1,step,lb);
    t[step]=lb;
    dfs(step+1,lr,step);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(2,1,-1);
        cout<<maxc<<endl;
        maxc=0;
    }
    return 0;
}
