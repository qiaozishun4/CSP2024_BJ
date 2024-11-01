#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        if(n<2) cout<<-1<<endl;
        else
        {
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
