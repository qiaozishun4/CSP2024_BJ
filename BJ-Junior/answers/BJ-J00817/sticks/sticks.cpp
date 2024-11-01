#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int num[21]={6,2,5,5,4,5,6,3,7,6};
void pin()
{
    int n;
    cin>>n;
    //cout<<n;
    string dp[100005];
    dp[0]=dp[1]="-1";
    dp[2]="1";
    for(int i=3;i<=100000;i++)
    {
        dp[i]="1000000";
        for(int j=0;j<=9;j++)
        {
            int id=i-num[j];
            if(id<0)continue;
            string s=dp[id];
            if(s=="-1")
            {
                s="";
                s+=char(j+'0');
                if(num[j]!=i||j==0)
                {
                    s="1000000";
                }
            }
            else
            {
                int ok=0;
                for(int k=0;k<s.size();k++)
                {
                    if(j==0&&k==0)continue;
                    if(j<=s[k]-'0')
                    {
                        string s2="";
                        s2+=j+'0';
                        s.insert(k,s2);
                        ok=1;
                        break;
                    }
                }
                if(ok==0)s="1000000";
            }
            if(stoi(s)<stoi(dp[i]))
                dp[i]=s;
        }
        if(dp[i]=="1000000")
        {
            dp[i]="-1";
        }
    }
    while(n--)
    {
        int t;
        cin>>t;
        cout<<dp[t]<<endl;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    pin();
    return 0;
}