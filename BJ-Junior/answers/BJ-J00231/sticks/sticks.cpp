#include<bits/stdc++.h>
using namespace std;
int ans[]={0,-1,1,7,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688,888},cost[]={6,2,5,5,4,5,6,3,7,5};
int n,cnt,t,mx,ot[55];
vector <char> dp[100005][2];
inline void init()
{   
    for(int i=2;i<=21;i++)
    {
        int cur=ans[i];
        while(cur)
        {
            char ier=cur%10+'0';
            dp[i][1].push_back(ier);
            if(i!=12&&i!=13&&i!=20) dp[i][0].push_back(ier);
            cur/=10;
        }
        
    } 
    dp[12][0].push_back('0');dp[12][0].push_back('0');
    dp[13][0].push_back('8');dp[13][0].push_back('0');
    dp[20][0].push_back('8');dp[20][0].push_back('8');dp[20][0].push_back('0');
    for(int i=22;i<=mx;i++)
    {
        int bounc=i/7*7;
        for(int j=1;j<=9;j++)
        {
            if(i-cost[j]<=bounc) 
            {
             //   cout<<"^^"<<endl;
                for(int k=0;k<dp[i-cost[j]][0].size();k++)
                {
                    dp[i][1].push_back(dp[i-cost[j]][0][k]);
                //    cout<<dp[i-cost[j]][k]<<" "<<k<<" "<<i-cost[j]<<endl;
                }
                char inr=j+'0';
                dp[i][1].push_back(inr);
                break;
            }
        }

        for(int j=0;j<=9;j++)
        {
            if(i-cost[j]<=bounc) 
            {
             //   cout<<"^^"<<endl;
                for(int k=0;k<dp[i-cost[j]][0].size();k++)
                {
                    dp[i][0].push_back(dp[i-cost[j]][0][k]);
                //    cout<<dp[i-cost[j]][k]<<" "<<k<<" "<<i-cost[j]<<endl;
                }
                char inr=j+'0';
                dp[i][0].push_back(inr);
                break;
            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>ot[i];
        mx=max(ot[i],mx);
    }
    init();
    for(int i=1;i<=t;i++)
    {
        if(ot[i]<=21) cout<<ans[ot[i]]<<endl;
        else 
        {
            for(int k=dp[ot[i]][1].size()-1;k>=0;k--)
            {
                cout<<dp[ot[i]][1][k];
            }
            cout<<endl;
        }
    }
    return 0;
}