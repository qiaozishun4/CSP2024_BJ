#include<bits/stdc++.h>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<-1;
            continue;
        }
        for(i=1;i<=n/7;i++)
        {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
