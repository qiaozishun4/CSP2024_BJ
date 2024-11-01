#include <bits/stdc++.h>
using namespace std;
long long ans=1e18;
long long n,t;
void dfs(long long cnt,long long sum)
{
    if(cnt<=0)
    {
        if(cnt==0)
            ans=min(ans,sum);
        return ;
    }
    if(sum!=0)dfs(cnt-6,sum*10+0);
    dfs(cnt-2,sum*10+1);
    dfs(cnt-5,sum*10+2);
    dfs(cnt-4,sum*10+4);
    dfs(cnt-6,sum*10+6);
    dfs(cnt-3,sum*10+7);
    dfs(cnt-7,sum*10+8);

}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;

        if(n%7==0)
        {
            while(n!=0){
                n-=7;cout<<8;}
            cout<<endl;
        }
        else if((n-1)%7==0)
        {
            cout<<10;
            n-=8;
            while(n!=0){
                n-=7;cout<<8;}
            cout<<endl;
        }
        else
        {
            dfs(n,0);
            if(ans==1e18)ans=-1;
            cout<<ans<<endl;
            ans=1e18;
        }
    }
    return 0;
}
