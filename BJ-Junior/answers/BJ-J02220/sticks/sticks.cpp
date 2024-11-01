#include<bits/stdc++.h>
using namespace std;
int p[50]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,206,208,288,688,888,1088};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        cout<<p[n]<<endl;
    }
    
    return 0;
}
