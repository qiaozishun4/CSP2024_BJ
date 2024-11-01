#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n[t];
    for(int i=0;i<t;i++)
    {
        cin>>n[i];
    }
    for(int i=0;i<t;i++)
    {
        if(n[i]==1) cout<<-1<<endl;
        if(n[i]==3) cout<<7<<endl;
        if(n[i]==10) cout<<22<<endl;
        if(n[i]==17) cout<<200<<endl;
        if(n[i]%7==0)
        {
            for(int j=1;j<=n[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==1&&n[i]!=1)
        {
            cout<<10;
            for(int j=2;j<=n[i]/7-1;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==2)
        {
            cout<<1;
            for(int j=1;j<=n[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==3 && n[i]!=3 && n[i]!=10 && n[i]!=17)
        {
            cout<<200;
            for(int j=1;j<=n[i]/7-2;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==4)
        {
            cout<<20;
            for(int j=1;j<=n[i]/7-1;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==5)
        {
            cout<<2;
            for(int j=1;j<=n[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(n[i]%7==6)
        {
            cout<<6;
            for(int j=1;j<=n[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }

    }
    return 0;
}
