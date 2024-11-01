#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int to,tot,lt;
}edge[N];
void addedge(int u,int v,int v1)
{
	edge[v1].to=v1;
	edge[v1].tot=v;
	edge[v1].lt=u;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        int a[N],dp[N],e[N];
        int n;
        bool b=0;
        dp[0]=0;
        e[0]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            dp[i]=0;
            e[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i]==a[j])
                {
                    b=1;
                    addedge(i,j,a[j]);
                    if(i=j-1)   e[j]+=a[j];
                    else    e[j]=e[j-1];
                    break;
                }
            }
        }
        if(b==0)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i]==edge[j].to)
                {
                    dp[i]=max(dp[i]+e[i-1]-e[edge[j].lt+1],dp[i-1]);
                }
                else    dp[i]=dp[i-1];
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
