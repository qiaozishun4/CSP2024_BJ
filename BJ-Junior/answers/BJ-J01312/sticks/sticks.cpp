#include <bits/stdc++.h>
using namespace std;
int t;
int s;
long long ans=1e18;
int a[7]={6,2,5,4,3,7};
int b[7]={0,1,2,4,7,8};
void dp(int s,long long num)
{
    if(s<0)
    {
        return;
    }
    if(s==0)
    {

        ans=min(ans,num);
        //cout<<num<<endl;
        return ;
    }
    num=num*10;
    for(int i=0;i<=5;i++)
    {
        if(i==0&&num==0)continue;
        num+=b[i];
        //cout<<num<<endl;
        if(s-a[i]<0)continue;
        if(s-a[i]>=0)dp(s-a[i],num);
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>s;
        dp(s,0);
        if(ans==1e18)cout<<-1<<endl;
        else cout<<ans<<endl;
        ans=1e18;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
