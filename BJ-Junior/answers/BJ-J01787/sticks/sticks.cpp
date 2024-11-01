#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN=1e5;
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        for(cin>>n;n;n-=7)
            cout<<8;
        cout<<endl;
    }
    return 0;
}
