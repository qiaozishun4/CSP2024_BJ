#include<iostream>
using namespace std;
const int N=2e5+10;
int a[N];
int n,ans;
void dfs(int cur,int pre0,int pre1,int sum)//0blue 1red
{
    if(cur>n)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(cur+1,pre0,cur,sum+(a[cur]==a[pre1]?a[cur]:0));
    dfs(cur+1,cur,pre1,sum+(a[cur]==a[pre0]?a[cur]:0));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}