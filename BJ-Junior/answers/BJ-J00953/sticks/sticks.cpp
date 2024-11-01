#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n%7==0)
        {
            ll nn=n/7;
            for(int i=1;i<=nn;i++)cout<<8;
        }
        else if(n%7==1)
        {
            ll nn=n/7-1;
            cout<<10;
            for(int i=1;i<=nn;i++)cout<<8;
        }
    }
    return 0;
}
