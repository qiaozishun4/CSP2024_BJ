#include<bits/stdc++.h>
using namespace std;
string smin(string a,string b)
{
    if(a.length()<b.length())
        return a;
    if(a.length()>b.length())
        return b;
    return min(a,b);
}
int st[10]={6,2,5,5,4,5,6,3,7,6};
char mini[10]={0,0,'1','7','4','2','6','8'};
string dp[100005];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    string bas="";
    for(int i=0;i<20000;++i)bas+='9';
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;dp[0]=dp[1]="0";
        if(n==1){cout<<"-1\n";continue;}
        //if(n==6){cout<<"6\n";continue;}
        fill(dp+2,dp+n+1,bas);
        dp[2]="1";dp[3]="7";dp[4]="4";
        dp[5]="5";dp[6]="6";dp[7]="8";
        for(int i=4;i<=n;++i)
        {
            //dp[i]=min(dp[i],dp[j]+mini[i-j]);
            for(int j=max(0,i-7);j<i-1;++j)
            {
                if(i-j==6)//0,6,9:0 can't be the top digit
                {
                    string w1=dp[j];
                    if(dp[j][0]<'6')
                        w1=string("")+w1[0]+"0"+w1.substr(1,w1.length()-1);
                        //w1.insert(1,'0');
                    else w1=string("6")+w1;
                    dp[i]=smin(dp[i],w1);
                    continue;
                }
                int pos=0;//where to insert the num
                if(dp[j]=="0")continue;
                for(;pos<dp[j].size();++pos)
                    if(dp[j][pos]>=mini[i-j])break;
                string new1=dp[j];new1=new1.substr(0,pos)+mini[i-j]+new1.substr(pos,new1.length()-pos);
                dp[i]=smin(dp[i],new1);
            }
        }
        cout<<dp[n]<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
