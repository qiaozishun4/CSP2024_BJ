#include<bits/stdc++.h>
using namespace std;
long long T,n;
int ans[50]={-1,1,7,4,5,6,8,10,18,22,26,28,68,88,108,188,248,228,208,288,688,888,10888,18888,22888,20888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        if(n<=25)
        {
        cout<<ans[n-1]<<endl;
        }
        if(n%7==0)
        {
            while(n>0)
            {
                n=n-7;
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=(n-1)/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
