#include<bits/stdc++.h>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==0||n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<"8";
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<"10";
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==2)
        {
            cout<<"1";
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3)
        {
            if(n==10)
            {
                cout<<"22"<<endl;
                continue;
            }
            if(n==3)
            {
                cout<<"7"<<endl;
                continue;
            }
            cout<<"200";
            for(int i=1;i<=n/7-2;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==4)
        {
            if(n==4)
            {
                cout<<"4"<<endl;
                continue;
            }
            cout<<"20";
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==5)
        {
            cout<<"2";
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6)
        {
            cout<<"6";
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
