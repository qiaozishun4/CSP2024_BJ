#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N],c[N],l[N],ans=-1e9;
int chk()
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i]!=0&&a[i]==a[l[i]])res+=a[i];
    }
    return res;
}
void dfs(int num)
{
    if(num==n)
    {
        ans=max(ans,chk());
        return;
    }
    c[num]=1;
    dfs(num+1);
    c[num]=2;
    dfs(num+1);
    c[num]=0;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","r",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        ans=-1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(a[i]==a[j])
                {
                    l[i]=j;
                    break;
                }
            }
        }
        dfs(1);
    }
    return 0;
}