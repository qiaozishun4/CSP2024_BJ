#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans,ans2;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(t=t;t>0;t--)
    {
        cin>>n;
        ans=0;
        if(n<=1)
        {
            ans=-1;
        }
        else if(n/7==0)
        {
            if(n==2)
            {
                ans=1;
            }

            else if(n==3)
            {
                ans=7;
            }
            else if(n==4)
            {
                ans=4;
            }
            else if(n==5)
            {
                ans=2;
            }
            else
            {
                ans=6;
            }
        }
        else if(n%7==0)
        {
            ans2=n/7;
        }
        else if(n%7==1)
        {
            ans=10;
            ans2=n/7-1;
        }
        else if(n%7==2)
        {
            ans=1;
            ans2=n/7;
        }
        else if(n%7==3)
        {
            ans=22;
            ans2=n/7-1;
        }
        else if(n%7==4)
        {
            ans=20;
            ans2=n/7-1;
        }
        else if(n%7==5)
        {
            ans=2;
            ans2=n/7;
        }
        else if(n%7==6)
        {
            ans=6;
            ans2=n/7;
        }
        if(ans!=0)
        {
            cout<<ans;
        }
        if(ans2!=0)
        {
            for(int i=1;i<=ans2;i++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
