#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int d[11]={6,2,5,5,4,4,6,3,7,6};
int que[51];
string dp[100001];//dp[i]:当用i根木棍时所得到的最小数
int fnd(string s)
{
    for(int i=0,l=s.size();i<l;i++)
    {
        if(s[i]!='0') return i;
    }
    return 0;
}
string mrge(string x,char y)
{
    x.push_back(y);
    sort(x.begin(),x.end());
    if(x[0]=='0') swap(x[0],x[fnd(x)]);
    if(x[0]!='0') return x;
    else return "";
}
bool cmp(string x,string y)//若x<y，则返回1
{
    if(x.size()==0) return 0;
    if(y.size()==0) return 1;
    if(x.size()!=y.size()) return x.size()<y.size();
    else return x<y;
}
string mn(string x,string y)
{
    return (cmp(x,y)?x:y);
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n=0;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>que[i];
        n=max(n,que[i]);
    }
    dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++)//枚举当前位选什么
        {
            if(i>d[j] && dp[i-d[j]]!="-1") dp[i]=mn(dp[i],mrge(dp[i-d[j]],j+'0'));
        }
        if(dp[i].size()==0) dp[i]="-1";
    }
    for(int i=1;i<=T;i++)
    {
        cout<<dp[que[i]]<<endl;
    }
    cout<<flush;
    return 0;
}
