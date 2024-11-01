#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000010];
long long ans=0;
void check(string s)
{
    long long cnt=0;
    int ylast=-1,llast=-1;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]=='0')
        {
            if(llast!=-1)
            {
                if(a[llast+1]==a[i+1])
                {
                    cnt+=a[i+1];
                }
            }
            llast=i;
        }
        if(s[i]=='1')
        {
            if(ylast!=-1)
            {
                if(a[ylast+1]==a[i+1])
                {
                    cnt+=a[i+1];
                }
            }
            ylast=i;
        }
    }
    //cout<<" "<<cnt<<endl;
    ans=max(cnt,ans);
}
void dfs(int step,string s)
{
    if(0.95*CLOCKS_PER_SEC<=clock()) return ;
    if(step==n)
    {
        //cout<<s;
        check(s);
        return ;
    }
    dfs(step+1,s+"0");
    dfs(step+1,s+"1");
    return ;
}
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,"");
    printf("%d\n",ans);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
