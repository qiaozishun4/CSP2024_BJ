#include <bits/stdc++.h>
using namespace std;
int check[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        int m;
        cin>>m;
        if(m%7==0)
        {
            for(int i=1;i<=m/7;i++)
            {
                cout<<8;
            }
        }
        else if(m%7==1)
        {
            if(m==1) cout<<-1;
            else
            {
                cout<<10;
                for(int i=1;i<m/7;i++)
                {
                    cout<<8;
                }
            }
        }
        else if(m%7==2)
        {
            cout<<1;
            for(int i=1;i<=m/7;i++)
            {
                cout<<8;
            }
        }
        else if(m%7==3)
        {
            if(m==3) cout<<7;
            else if(m==17)
                cout<<200;
            else
            {
                cout<<22;
                for(int i=1;i<m/7;i++)
                {
                    cout<<8;
                }
            }
        }
        else if(m%7==4)
        {
            if(m==4) cout<<4;
            else
            {
                cout<<20;
                for(int i=1;i<m/7;i++)
                {
                    cout<<8;
                }
            }
        }
        else if(m%7==5)
        {
            cout<<2;
            for(int i=1;i<=m/7;i++)
            {
                cout<<8;
            }
        }
        else if(m%7==6)
        {
            cout<<6;
            for(int i=1;i<=m/7;i++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
