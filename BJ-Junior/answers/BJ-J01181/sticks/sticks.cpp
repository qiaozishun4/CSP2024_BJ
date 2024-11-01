#include <bits/stdc++.h>

using namespace std;

int num[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string ans;
string cpr(string s1,string s2)
{
    if(s1.size()>s2.size())return s2;
    if(s1.size()<s2.size())return s1;
    if(s1.size()==s2.size())return s1<s2?s1:s2;
}
void dfs(int tot,string s)
{
    if(s[0]=='0')return;
    if(ans.size()&&ans==cpr(ans,s))return;
    if(tot==1)return;
    if(tot==0)
    {
        ans=s;
        return;
    }
    for(int i=0;i<9;i++)
    {
        char c=i+'0';
        if(tot-num[i]>=0)
        {
            s+=c;
            dfs(tot-num[i],s);
            s.erase(s.size()-1);
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("-1\n");
            continue;
        }
        if(n<14)
        {
            string s;
            ans.clear();
            dfs(n,s);
            cout<<ans<<endl;
            continue;
        }
        int n8=n/7;
        if(n%7==0)
        {
            for(int j=1;j<=n8;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==1)
        {
            printf("10");
            for(int j=1;j<=n8-1;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==2)
        {
            printf("1");
            for(int j=1;j<=n8;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==3)
        {
            printf("200");
            for(int j=1;j<=n8-2;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==4)
        {
            printf("20");
            for(int j=1;j<=n8-1;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==5)
        {
            printf("2");
            for(int j=1;j<=n8;j++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==6)
        {
            printf("6");
            for(int j=1;j<=n8;j++)printf("8");
            printf("\n");
            continue;
        }
    }
    return 0;
}
