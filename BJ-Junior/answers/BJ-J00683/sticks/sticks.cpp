#include <iostream>
using namespace std;
long long n,t,ans,x;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n%7==0)
        {
            ans=1;
            x=0;
            for(int j=1;j<=n/7;j++)
            {
                x+=ans;
                ans=ans*10;
            }
            cout<<x*8<<endl;
        }
        else if((n-1)%7==0)
        {
            ans=1;
            x=0;
            if(n==8)
            {
                cout<<"10"<<endl;
                return 0;
            }
            for(int j=2;j<=(n-1)/7;j++)
            {
                x+=ans;
                ans=ans*10;
            }
            x=x*8;
            x+=ans*10;
            cout<<x<<endl;
        }
    }
    return 0;
}
