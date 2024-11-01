#include<bits/stdc++.h>
using namespace std;
int a[15]={6,2,5,5,4,5,6,3,7,6,0,0,0,0,0};
int cnt;
int ans[50005];
void dfs(int n)
{
    if(n<=1)
    {
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        if(n-a[i]==0)
        {
            cnt++;
            ans[cnt]=i;
            return ;
        }
        dfs(n-a[i]);
        if(cnt!=0)
        {
            cnt++;
            ans[cnt]=i;
            return ;
        }
    }
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            break;
        }
        for(int i=1;i<=9;i++)
        {
            int k;
            k=n-i;
            dfs(k);
            if(cnt!=0)
            {
                for(int j=cnt;j>=1;j--)
                {
                    cout<<ans[i];
                }
                cout<<endl;
                break;
            }
        }
        if(cnt==0)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
