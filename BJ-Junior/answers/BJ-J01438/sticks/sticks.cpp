#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //freopen("sticks.in","w",stdin);
    cin>>n;
    for(int o=1;o<=n;o++)
    {
        int s=0,k=0;
        cin>>s;
        if(s==1)
        {
            cout<<'-';

        }
        k=s/7;
        s=s%7;
        if(s==0)
        {
            for(int i=1;i<=k;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==1)
        {
            if(k>=1)
                cout<<10;
            else
                cout<<1;
            for(int i=1;i<=k-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==2)
        {
            cout<<1;
            for(int i=1;i<=k;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==3)
        {
            if(k>=1)
                cout<<40;
            else
                cout<<7;
            for(int i=1;i<=k-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==4)
        {
            if(k>=1)
                cout<<20;
            else
                cout<<4;
            for(int i=1;i<=k-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==5)
        {
            cout<<2;
            for(int i=1;i<=k;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        if(s==6)
        {
            if(k>=1)
                cout<<80;
            else
                cout<<6;
            for(int i=1;i<=k-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}