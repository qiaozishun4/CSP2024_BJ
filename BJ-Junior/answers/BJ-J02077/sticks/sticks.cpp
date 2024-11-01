#include<iostream>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n%7==0)
        {
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7==1)
        {
            cout<<10;
            for(int j=2;j<=n/7;j++)
            {
                cout<<8;
            }
        }

    }
    return 0;
}
