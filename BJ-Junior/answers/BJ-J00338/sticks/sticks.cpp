#include <iostream>
using namespace std;
#define ll long long
ll num[10]={6,2,5,5,4,5,6,3,7,6};
ll T,n;
ll cc;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        cc=n/7;
        for(int i=1; i<=cc; i++)
        {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
