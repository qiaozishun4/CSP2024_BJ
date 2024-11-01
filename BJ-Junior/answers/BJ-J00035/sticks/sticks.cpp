#include<bits/stdc++.h>
using namespace std;
int t[10]={6,2,5,5,4,5,6,3,7,6},n;
long long mi=1e18;
void dfs(int step,long long ans,int c)
{
    //cout<<step<<" "<<ans<<" "<<c<<endl;
    if(c==n)
    {
        mi=min(mi,ans);
        //cout<<mi<<endl;
        return;
    }
    ans*=10ll;
    for(int i=0;i<10;i++)
    {
        if(step==1&&i==0) continue;
        if(n-c-t[i]>1||n-c-t[i]==0)
        {
            ans-=ans%10;
            ans+=i*1ll;
            dfs(step+1,ans,c+t[i]);
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<=27)
        {
            mi=1e18;
            dfs(1,0,0);
            if(mi==1e18) cout<<-1;
            else cout<<mi;
        }
        else if(n%7==0)
            for(int i=1;i<=n/7;i++)
                cout<<8;
        else
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
                cout<<8;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
