#include<iostream>
using namespace std;
int t,n,m,l;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }
        if(n==4)
        {
            cout<<"4\n";
            continue;
        }
        if(n==3)
        {
            cout<<"7\n";
            continue;
        }
        if(n==10)
        {
            cout<<"22\n";
            continue;
        }
        m=(n+6)/7;
        l=m*7-n;
        if(!l)
        {
            for(int i=1;i<=m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(l<2)
        {
            cout<<6;
            for(int i=1;i<m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(l<3)
        {
            cout<<2;
            for(int i=1;i<m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(l<4)
        {
            cout<<20;
            for(int i=2;i<m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(l<5)
        {
            cout<<200;
            for(int i=3;i<m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(l<6)
        {
            cout<<1;
            for(int i=1;i<m;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        cout<<10;
        for(int i=2;i<m;i++)
        {
            cout<<8;
        }
        cout<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}