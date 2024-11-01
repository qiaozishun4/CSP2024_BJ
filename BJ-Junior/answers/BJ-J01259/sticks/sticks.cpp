#include<bits/stdc++.h>
using namespace std;
const int num[]={6,2,5,5,4,5,6,3,7,6};
int znum(int a)
{
    int ret=0;
    while(a)
    {
        ret+=num[a%10];
        a/=10;
    }
    return ret;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=0;i<n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==1)
        {
            cout<<10;
            n-=8;
            for(int i=0;i<n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else
        {
            int mn=100000,mx=0;
            int minn=10000005;
            for(int i=mx;i<mn;i++)
            {
                minn=min(znum(i),minn);
            }
            cout<<minn<<endl;
        }
    }
    return 0;
}
