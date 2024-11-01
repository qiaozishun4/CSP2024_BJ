#include<iostream>
using namespace std;
#define ll long long
ll T;
ll n;
bool b;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll x=n/7;
        if(n%7==0&&!b)
        {
            b=true;
        }
        if(b)
        {
            for(int i=1;i<=x;i++)
            {
                cout<<8;
            }
        }
        else{
            cout<<10;
            x=(n-1)/7;
            for(int i=1;i<x;i++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
