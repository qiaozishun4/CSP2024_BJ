#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool vis[100005];
int flag[100005],idx=1,p=1;
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
    sort(a+1,a+n+1);//shengxu
    flag[1]=1;
    for(int i=2;i<=n;i++)
    {
        flag[++idx]=i;
        if(a[i]>a[flag[p]])
        {
            vis[flag[p]]=1;
            p++;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
