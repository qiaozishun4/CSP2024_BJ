#include<bits/stdc++.h>
using namespace std;
int n,m,k,T,x,y,d;
int dp[100005];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    dp[1]=-1;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=6;
    dp[7]=8;
    while(T--)
    {
        cin>>n;
        if(n>=1&&n<=7)
        {
            cout<<dp[n]<<endl;
            continue;
        }
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==2)
        {
            cout<<1;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==3)
        {
            cout<<22;
            for(int i=1;i<=n/7-1;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==4)
        {
            cout<<20;
            for(int i=1;i<=n/7-1;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
    }
    return 0;
}
