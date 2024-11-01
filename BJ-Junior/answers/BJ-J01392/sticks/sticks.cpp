#include<bits/stdc++.h>
using namespace std;
long long ans[1000005];
long long ansans[1000005];
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long s,ansanss=1000005,num,mx=0;
bool flag=false;
void my_min()
{
    bool f=false;
    if(s<ansanss)
        f=true;
    for(int i=1;i<=s;i++)
        if(ans[i]<ansans[i]||f)
        {
            f=true;
            break;
        }
        else if(ans[i]>ansans[i])
            return ;
    if(f)
    {
        ansanss=s;
        for(int i=1;i<=s;i++)
            ansans[i]=ans[i];
    }
    return ;
}
void dfs(int n)
{
    if(s>=ansanss&&n!=0)
        return ;
    if(n==0)
    {
        my_min();
        return ;
    }
    for(int i=(!flag?1:0);i<=9;i++)
    {
        if(n>=a[i])
        {
            flag=true;
            ans[++s]=i;
            dfs(n-a[i]);
            ans[s--]=0;
        }
    }
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        flag=false,s=0,ansanss=1000005;
        memset(ans,0,sizeof(ans));
        memset(ansans,0x3f3f3f,sizeof(ansans));
        cin>>num;
        dfs(num);
        if(ansanss!=1000005)
             for(int j=1;j<=ansanss;j++)
                 cout<<ansans[j];
        else
            cout<<-1;
        cout<<endl;
    }
    return 0;
}
