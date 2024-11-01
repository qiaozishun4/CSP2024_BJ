#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100005];
int v[15]={6,2,5,5,4,5,6,3,7,6};
string s[100005];
int p[15]={8,0,6,9,2,3,5,4,7,1};
bool cmp(string s1,string s2)
{
    int n1=s1.size();
    int n2=s2.size();
    if(n1!=n2)
        return n1<n2;
    return s1<s2;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1; i<=n/7; i++)cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==6)
        {
            cout<<6;
            for(int i=1; i<n/7; i++)cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==5)
        {
            cout<<2;
            for(int i=1; i<n/7; i++)cout<<8;
            cout<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<10; i++)
        {
            int tmp=v[p[i]];
            for(int j=tmp; j<=n; j++)
            {
                if(p[i]==0&&s[j-tmp]=="")continue;
                if(cmp(s[j],s[j-tmp]+(char)(p[i]+'0')))
                {
                    dp[j]=dp[j-tmp]+v[i];
                    s[j]=s[j-tmp]+(char)(p[i]+'0');
                }
            }
        }
        cout<<s[n]<<endl;
    }
    return 0;
}