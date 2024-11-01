#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans;
int num[8]={-1,-1,1,7,4,2,0,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        if(n==1)
        {
            ans=-1;
            cout<<ans<<endl;
        }
        else if(n==6)
        {
            ans=6;
            cout<<ans<<endl;
        }
        else if(n<=7)
        {
            ans=num[n];
            cout<<ans<<endl;
        }
        else if(n%7==0)
        {
            int p=n/7;
            for(int i=0;i<p;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(((n-1)%7)==0&&n>15)
        {
            int p=(n-1)/7;
            p-=2;
            for(int i=0;i<p;i++)
            {
                cout<<8;
            }
            cout<<0<<1<<8<<endl;
        }
        else
        {
            ans=-1;
            cout<<ans<<endl;
        }
    }
    return 0;
}