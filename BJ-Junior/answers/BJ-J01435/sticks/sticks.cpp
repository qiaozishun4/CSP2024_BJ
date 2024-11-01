#include<bits/stdc++.h>
using namespace std;
int t,n,minn=100001,x,y,m[8]={-1,-1,1,7,4,2,0,8};
bool f=true;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n;
        if(n<6)
        {
            cout<<m[n]<<endl;
            continue;
        }
        if(n==6)
        {
            cout<<6<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8; 
            }
            cout<<endl;
            continue;
        }
        // for(int i=1;i<n/7+1;i++)
        // {
        //     x=n-i*7;
        //     if(x==1)
        //     {
        //         f=false;
        //     }
        //     for(int j=2;j<=7;j++)
        //     {
        //         if(x-j>=2&&x-j<7)
        //         {
        //             f=false;
        //         }
        //     }
        //     minn=min(minn,y);
        // }
        // if(f)
        cout<<-1<<endl;
        // else
        //     cout<<minn<<endl;
    }
}