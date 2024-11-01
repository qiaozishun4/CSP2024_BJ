#include<bits/stdc++.h>
using namespace std;
int n,t;
string dp[100005];
string minn(string a,string b)
{
    if(a.size()!=b.size())
    {
        if(a.size()<b.size())
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<b[i])
        {
            return a;
        }
        else if(b[i]<a[i])
        {
            return b;
        }
    }
    return a;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            dp[i] = "-1";
        }
        for(int i=1;i<=n;i++)
        {
            int f=0;
            if(i-2>=0&&dp[i-2]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    dp[i] = dp[i-2]+"1";
                }
                else
                {
                    dp[i] = minn(dp[i],dp[i-2]+"1");
                }
            }
            if(i-3>=0&&dp[i-3]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    dp[i] = dp[i-3]+"7";
                }
                else
                {
                    dp[i] = minn(dp[i],dp[i-3]+"7");
                }
            }
            if(i-4>=0&&dp[i-4]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    dp[i] = dp[i-4]+"4";
                }
                else
                {
                    dp[i] = minn(dp[i],dp[i-4]+"4");
                }
            }
            if(i-5>=0&&dp[i-5]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    dp[i] = dp[i-5]+"2";
                }
                else
                {
                    dp[i] = minn(dp[i],dp[i-5]+"2");
                }
            }
            if(i-6>=0&&dp[i-6]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    if((i-6)>0)
                    {
                        dp[i] = dp[i-6]+"0";
                    }
                    else
                    {
                        dp[i] = dp[i-6]+"6";
                    }
                }
                else
                {
                    if((i-6)>0)
                    {
                        dp[i] = minn(dp[i],dp[i-6]+"0");
                    }
                    else
                    {
                        dp[i] = minn(dp[i],dp[i-6]+"6");
                    }
                }
            }
            if(i-7>=0&&dp[i-7]!="-1")
            {
                if(f==0)
                {
                    f = 1;
                    dp[i] = dp[i-7]+"8";
                }
                else
                {
                    dp[i] = minn(dp[i],dp[i-7]+"8");
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}