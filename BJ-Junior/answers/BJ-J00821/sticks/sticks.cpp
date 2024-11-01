#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[11]={0,6,2,5,5,4,5,6,3,7,6};
int b[11]={0,0,1,2,3,4,5,6,7,8,9};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        if(n<=1)
        {
            cout<<"-1"<<'\n';
            continue;
        }
        if(n<=7&&n!=6)
        {
            for(int i=1;i<=10;i++)
            {
                if(n==a[i])
                {
                     cout<<b[i]<<'\n';
                     break;
                }
            }
            continue;
        }
        if(n==6)
        {
            cout<<6<<'\n';
            continue;
        }
        if(n%7==0)
        {
            int ans=8;
            int x=(n/7);
            int cnt=1;
            for(int j=1;j<x;j++)
            {
                cnt*=10;
                ans+=(8*cnt);
            }
            cout<<ans<<'\n';
            continue;
        }
        int ans=8;
        int cnt=1;
        n-=7;
        while(1)
        {
            if(n-6>1)
            {
                cnt*=10;
                continue;
            }
            else if(n-6==0)
            {
                n-=6;
                cnt*=10;
                ans+=(6*cnt);
                break;
            }
            else if(n-5==0)
            {
                n-=5;
                cnt*=10;
                ans+=(2*cnt);
                break;
            }
            else if(n-4==0)
            {
                n-=4;
                cnt*=10;
                ans+=(4*cnt);
                break;
            }
            else if(n-3==0)
            {
                n-=3;
                cnt*=10;
                ans+=(7*cnt);
                break;
            }
            else if(n-2==0)
            {
                n-=2;
                cnt*=10;
                ans+=(1*cnt);
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
