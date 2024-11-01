#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],t,ans,sum;
bool b[200005];
void pan()
{
    sum=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(b[i]==b[j])
            {
                if(a[i]==a[j])
                {
                    sum+=a[i];
                }
                break;
            }
        }
    }
    ans=max(ans,sum);
    return ;
}
void dfs(long long wei,bool se)//1 hong 0 lan
{
    b[wei]=se;
    if(wei>=n)
    {
        pan();
        return ;
    }
    dfs(wei+1,1);
    dfs(wei+1,0);

}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        dfs(1,1);
        dfs(1,0);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}