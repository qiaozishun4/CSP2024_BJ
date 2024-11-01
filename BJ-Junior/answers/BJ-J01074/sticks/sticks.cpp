#include<bits/stdc++.h>
using namespace std;
int t,n,ans=1e9;
int cost[10]={6,2,5,5,4,5,6,3,7,6};

void dfs(int n,int num)
{
    //cout<<n<<" "<<num<<endl;
    if(n==0)
    {
        ans=min(ans,num);
        return;
    }
    else
    {
        if(num==0)
        {
            for(int i=1;i<10;i++)
            {
                if(n-cost[i]>=0)
                {
                    dfs(n-cost[i],num*10+i);
                }
            }
        }
        else
        {

            for(int i=0;i<10;i++)
            {
                if(n-cost[i]>=0)
                {
                    dfs(n-cost[i],num*10+i);
                }
            }
        }
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=1e9;
        cin>>n;
        dfs(n,0);
        if(ans!=1e9) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
