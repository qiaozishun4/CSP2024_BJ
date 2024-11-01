#include<bits/stdc++.h>
using namespace std;
string dp[100010],tmp="";
map<char,int> mp={{'0',6},{'1',2},{'2',5},{'3',5},{'4',4},{'5',5},{'6',6},{'7',3},{'8',7},{'9',6}};
map<int,string> mp2={{1,"108"},{2,"188"},{3,"200"},{4,"208"},{5,"288"},{6,"688"}};
void cmp(string &minn,string x)
{
    if(x.size()<minn.size())
    {
        minn=x;
        return;
    }
    if(x.size()>minn.size())return;
    for(int i=0;i<minn.size();i++)
    {
        if(x[i]<minn[i])
        {
            minn=x;
            return;
        }
        else if(x[i]>minn[i])
        {
            return;
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
        ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<=100;i++)
    {
        tmp+="9";
        dp[i]="-1";
    }
    dp[0]="";
    dp[1]="-1";
    dp[2]="1";
    dp[3]="7";
    dp[4]="4";
    dp[5]="2";
    dp[6]="6";
    dp[7]="8";
    for(int i=8;i<=100;i++)
    {
        string minn=tmp;
        for(char j='0';j<='9';j++)
        {
            if(dp[i-mp[j]]!="-1")
            {
                cmp(minn,dp[i-mp[j]]+j);
            }
        }
        dp[i]=minn;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int x;
        cin>>x;
        if(x<=100)
        {
            cout<<dp[x]<<'\n';
        }
        else
        {
            if(x%7==0)
            {
                for(int i=0;i<x/7;i++)
                {
                    cout<<'8';
                }
            }
            else
            {
                cout<<mp2[x%7];
                for(int i=2;i<x/7;i++)
                {
                    cout<<'8';
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}