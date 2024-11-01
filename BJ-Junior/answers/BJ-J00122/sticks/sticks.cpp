#include<iostream>
#include<cstdio>
using namespace std;

long long t,n,tn;
long long num[10]={6,2,5,5,4,5,6,3,7,6};
long long nn[8]={0,0,1,7,4,2,0,8};
long long sum=1e18;

void dfs(long long ans)
{
    if(n==0)
    {
        sum=min(sum,ans);
        return ;
    }


    for(int i=7;i>=2;i--)
    {
        if(n-i<0)continue;
        if(n==tn && i==6)
        {
            n-=i;
            dfs(ans*10+6);
            n+=i;
        }
        else
        {
            n-=i;
            dfs(ans*10+nn[i]);
            n+=i;

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
        if(n%7==0)
        {
            while(n>0)
            {
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            n-=8;
            while(n>0)
            {
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        tn=n;
        sum=1e18;
        dfs(0);

        if(sum==1e18)
        {
            cout<<-1<<endl;
            continue;
        }


        cout<<sum<<endl;
        /*
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n<=7)
        {
            if(n==6)cout<<6<<endl;
            else cout<<nn[n]<<endl;
        }
        for(int i=2;i<=7;i++)
        {
            for(int j=i;j<=n;j++)
            {
                dp[j]=dp[j-i]*10+nn[i];
            }
        }
        */
    }


    return 0;
}
