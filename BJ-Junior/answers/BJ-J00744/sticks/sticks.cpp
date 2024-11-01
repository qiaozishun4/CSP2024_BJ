#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,q,needed[10]={6,2,5,5,4,5,6,3,7,6};
string plan,ans="",ans0="";
void dfs(int step,int sum)
{
    if (sum>n)return;
    if (sum==n)
    {
        if (plan<ans&&plan.size()<=ans.size())ans=plan;
        //cout<<plan<<endl;
        return;
    }
    for (int i=9;i>=0;i--)
    {
        if (step==1&&i==0)continue;
        plan=plan+char(i+48);
        dfs(step+1,sum+needed[i]);
        plan.erase(plan.size()-1,1);

    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>n;
        ans.resize(100005);
        ans0.resize(100005);
        for (int i=0;i<=100000;i++)
        {
            ans[i]=ans0[i]='9';
        }
        dfs(1,0);
        if (ans!=ans0)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
