#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt[15]={6,2,5,5,4,5,6,3,7,6};
string dp[N],dp1[N];
bool vis1[N],vis2[N];
bool big(string s1,string s2)
{
    if(s1.size()!=s2.size()) return s1.size()>s2.size();
    else return s1>s2;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    dp[2]=dp1[2]="1";
    dp[3]=dp1[3]="7";
    dp[4]=dp1[4]="4";
    dp[5]=dp1[5]="2";
    dp[6]="0";
    dp1[6]="6";
    dp[7]=dp1[7]="8";
    vis1[1]=vis2[1]=1;
    for(int i=8;i<N;i++)
    {
        string minn=".";
        for(int j=0;j<=9;j++)
        {
            if(vis1[i-cnt[j]]) continue;
            else
            {
                char a=j+'0';
                if(minn==".")
                {

                    minn=a+dp[i-cnt[j]];
                }
                else
                {
                    if(big(minn,a+dp[i-cnt[j]]))
                    {
                        minn=a+dp[i-cnt[j]];
                    }
                }
            }

        }
        if(minn==".") vis1[i]=1;
        else dp[i]=minn;
        minn=".";
        for(int j=1;j<=9;j++)
        {
            if(vis1[i-cnt[j]]) continue;
            else
            {
                char a=j+'0';
                if(minn==".")
                {

                    minn=a+dp[i-cnt[j]];
                }
                else
                {
                    if(big(minn,a+dp[i-cnt[j]]))
                    {
                        minn=a+dp[i-cnt[j]];
                    }
                }
            }

        }
        if(minn==".") vis2[i]=1;
        else dp1[i]=minn;

    }
    int t;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        if(vis2[p]) cout<<-1<<endl;
        else cout<<dp1[p]<<endl;
    }

    return 0;
}
