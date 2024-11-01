#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int main()
{
    freopen("sticks.in",r,stdin);
    freopen("sticks.out",w,stdout);
    int t,n;
    dp[1]=-1;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=9;
    dp[7]=8;
    dp[8]=18;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=9;j<=n;j++)
        {
            if(dp[j]==0)dp[j]=min(dp[j-7]*10+8,min(dp[j-6]*10+0,min(dp[j-5]*10+2,min(dp[j-4]*10+4,min(dp[j-3]*10+7,dp[j-2]*10+1))));
        }
        if(dp[n]>0){int g=dp[n];
        int tmp[10],b=9;
        while(g!=0)
        {
            if(g%10!=0)b=min(b,g%10);
            tmp[g%10]++;
            g/=10;
        }
        cout<<b;
        tmp[b]--;
        for(int j=0;j<=9;j++)
        {
            for(int k=1;k<=tmp[j];k++)
            {
                cout<<j;
            }
        }cout<<endl;}
        else cout<<-1<<endl;
    }
    
    return 0;
}