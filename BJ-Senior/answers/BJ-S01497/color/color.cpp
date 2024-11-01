#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n;
int color[200010];
int ans=0;
void dfs(int step)
{
    if(step>n)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(color[j]==color[i])
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
        return;
    }
    color[step]=1;
    dfs(step+1);
    color[step]=2;
    dfs(step+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        memset(color,0,sizeof(color));
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
