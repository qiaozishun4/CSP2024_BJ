#include<bits/stdc++.h>
using namespace std;
int check[10]={6,2,5,5,4,5,6,3,7,6};
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
        int k=n/7;
        if(n%7==0)
        {
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        if(n%7==1)
        {
            if(k==0)cout<<-1<<endl;
            else{
                cout<<10;
                for(int i=1;i<k;i++)cout<<8;
                cout<<endl;
            }
        }
        if(n%7==2)
        {
            cout<<1;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        if(n%7==3)
        {
            if(k==0)cout<<7;
            else if(k==1)cout<<22;
            else{
                cout<<200;
                for(int i=1;i<=k-2;i++)cout<<8;
            }
            cout<<endl;
        }
        if(n%7==4)
        {
            if(k==0)cout<<4;
            else{
                cout<<20;
                for(int i=1;i<k;i++)cout<<8;
            }
            cout<<endl;
        }
        if(n%7==5)
        {
            cout<<2;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        if(n%7==6)
        {
            cout<<6;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}