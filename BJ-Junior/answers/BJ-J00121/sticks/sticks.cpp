#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string last="2147483647";
string ans="";
void dfs(int x,int y)
{
    if(x<=1)
    {
        if(ans.length()>1)
        {
        }
        else
        {
            cout<<-1<<endl;
        }
        return;
    }
    if(y==1)
    {
        for(int i=1;i<9;i++)
        {
            if(x==s[i])
            {
                ans+=i+'0';
                int a=min(atoi(last.c_str()),atoi(ans.c_str()));
                ans=to_string(a);
                last=ans;
                return;
            }
        }
        for(int i=1;i<9;i++)
        {
            if(x>s[i])
            {
                ans+=i+'0';
                dfs(x-s[i],y+1);
                ans.erase(ans.end()-1);
            }
        }
    }
    else
    {
        for(int i=0;i<9;i++)
        {
            if(x==s[i])
            {
                ans+=i+'0';
                int a=min(atoi(last.c_str()),atoi(ans.c_str()));
                ans=to_string(a);
                last=ans;
                return;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(x>s[i])
            {
                ans+=i+'0';
                dfs(x-s[i],y+1);
                ans.erase(ans.end()-1);
            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        dfs(n,1);
        if(last!="2147483647")
        {
            cout<<last<<endl;
        }
        ans="";
        last="2147483647";
    }
return 0;
}
