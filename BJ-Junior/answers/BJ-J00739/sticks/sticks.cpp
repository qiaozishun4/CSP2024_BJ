#include<bits/stdc++.h>
using namespace std;
int f=0;
string ans="";
int a[10]={8,0,6,9,2,3,5,4,7,1};
int num[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int k,int n,string s)
{
    if(k<0) return;
    if(k==0)
    {
        //cout<<"tst::_sz::"<<s<<" "<<ans.size()<<" "<<s.size()<<endl;
        if(ans=="") ans=s;
        else
        {
            if(ans.size()>s.size()) ans=s;
            else if(ans.size()==s.size())
            {
                for(int i=0;i<ans.size();i++)
                    if(ans[i]>s[i])
                    {
                        ans=s;
                        break;
                    }
                    else if(ans[i]<s[i]) break;
            }
        }
        f=1;
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(n==1 && a[i]==0) continue;
        dfs(k-num[a[i]],n+1,s+char(a[i]+'0'));
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        f=0;
        ans="";
        cin>>n;
        if(n>=100 && n%7==0)
        {
            for(int i=0;i<n/7;i++) cout<<8;
            cout<<endl;
        }
        else if(n>=100 && n%7==1)
        {
            cout<<10;
            for(int i=0;i<(n-1)/7-1;i++) cout<<8;
            cout<<endl;
        }
        else
        {
            dfs(n,1,"");
            if(f==0) cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}
