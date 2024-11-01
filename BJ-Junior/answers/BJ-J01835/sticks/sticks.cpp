#include<bits/stdc++.h>
using namespace std;
string dp[100005];
int n,t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=100000;i++)
    {
        string s="",s1="",s2="",s3="",s4="",s5="",ans="-1";
        if(i-2>=0)
        {
            s=dp[i-2]+"1";
            if((ans=="-1"||s<=ans||s.size()<ans.size())&&s[0]!='-') ans=s;
        }
        if(i-3>=0)
        {
            s1=dp[i-3]+"7";
            if((ans=="-1"||s1<=ans||s1.size()<ans.size())&&s1[0]!='-') ans=s1;
        }
        if(i-4>=0)
        {
            s2=dp[i-4]+"4";
            if((ans=="-1"||s2<=ans||s2.size()<ans.size())&&s2[0]!='-') ans=s2;
        }
        if(i-5>=0)
        {
            s3=dp[i-5]+"2";
            if((ans=="-1"||s3<=ans||s3.size()<ans.size())&&s3[0]!='-') ans=s3;
        }
        if(i-6>=0)
        {
            s4=dp[i-6]+"6";
            if((ans=="-1"||s4<=ans||s4.size()<ans.size())&&s4[0]!='-') ans=s4;
            if(dp[i-6].size()>=1)
            {
                s4=dp[i-6]+"0";
                if((ans=="-1"||s4<=ans||s4.size()<ans.size())&&s4[0]!='-') ans=s4;
            }
        }
        if(i-7>=0)
        {
            s5=dp[i-7]+"8";
            if((ans=="-1"||s5<=ans||s5.size()<ans.size())&&s5[0]!='-') ans=s5;
        }
        dp[i]=ans;
    }
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}