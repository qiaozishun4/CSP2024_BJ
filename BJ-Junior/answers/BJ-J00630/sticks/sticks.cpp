#include<bits/stdc++.h>
using namespace std;
int a[14]={-1,-1,1,7,4,2,6,12,10,18,23,20,28,68};
int b[10]={6,2,5,5,4,5,6,3,7,6};
int t;
int n;
bool check(string ans,string s)
{
    if(ans.size()>s.size())
            return true;
    else if(ans.size()==s.size()){
        for(int i=0;i<s.size();i++)
        {
            if(ans[i]>s[i]){
                return true;
            }
            else if(ans[i]<s[i])
                return false;
        }
    }
    return false;
}
string ans,maxz;
void dfs(string s,int sumn)
{
    if(sumn>n)
        return ;
    if(sumn==n){
        if(check(ans,s))
            ans=s;
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        dfs(s+to_string(i),sumn+b[i]);
    }

}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    for(int i=1;i<=100000;i++)
        maxz+="9";
    while(t--)
    {
        ans=maxz;
        cin>>n;
        if(n<=13)
            cout<<a[n];
        else
        {
            for(int i=1;i<=9;i++)
            {
                dfs(to_string(i),b[i]);
            }
            if(ans==" ")
                cout<<-1;
            else
                cout<<ans;
        }
        cout<<endl;

    }
    return 0;
}

