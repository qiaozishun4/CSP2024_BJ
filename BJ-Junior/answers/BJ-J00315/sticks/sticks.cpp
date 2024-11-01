#include <bits/stdc++.h>
using namespace std;

int nums[10];
string buffer[100010];

string dp(int sticks,int depth)
{
    if(sticks<2)
    {
        return "-1";
    }else if(buffer[sticks]!="-1"&&(depth!=0||buffer[sticks][0]!='0'))
    {
        return buffer[sticks];
    }else
    {
        int mn=9999999;
        string ans="";
        for(int i=0;i<=9;i++)
        {
            if(i==0&&depth==0)
            {
                continue;
            }
            int tn=0;
            string t;
            if(sticks-nums[i]==0)
            {
                t=i+'0';
                tn=i;
                if(tn<=mn)
                {
                    mn=tn;
                    ans=t;
                }
            }else
            {
                t=dp(sticks-nums[i],depth+1);
                if(t!="-1")
                {
                    t=char(i+'0')+t;
                    int a=1;
                    for(int j=t.length()-1;j>=0;j--)
                    {
                        tn=tn+(t[j]-'0')*a;
                        a=a*10;
                    }
                    if(tn<=mn)
                    {
                        mn=tn;
                        ans=t;
                    }
                }
            }
        }
        if(ans=="")
        {
            return "-1";
        }
        if(buffer[sticks]=="-1")
        {
            buffer[sticks]=ans;
        }
        return ans;
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<10010;i++)
    {
        buffer[i]="-1";
    }
    nums[0]=6;
    nums[1]=2;
    nums[2]=5;
    nums[3]=5;
    nums[4]=4;
    nums[5]=5;
    nums[6]=6;
    nums[7]=3;
    nums[8]=7;
    nums[9]=6;

    buffer[6]="0";
    buffer[2]="1";
    buffer[5]="2";
    buffer[4]="4";
    buffer[3]="7";
    buffer[7]="8";
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        cout<<dp(n,0)<<endl;
    }
    return 0;
}
