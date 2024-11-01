#include<iostream>
using namespace std;
int T;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int x;
        cin>>x;
        if(x<7)
        {
            if(x==1)cout<<-1<<endl;
            else if(x==2)cout<<1<<endl;
            else if(x==3)cout<<7<<endl;
            else if(x==4)cout<<4<<endl;
            else if(x==5)cout<<2<<endl;
            else if(x==6)cout<<6<<endl;
        }
        else if(x%7==0)
        {
            for(int i=1;i<=x/7;i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==1)
        {
            cout<<10;
            for(int i=1;i<=(x/7-1);i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==2)
        {
            cout<<1;
            for(int i=1;i<=x/7;i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==3)
        {
            cout<<23;
            for(int i=1;i<=(x/7-1);i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==4)
        {
            cout<<20;
            for(int i=1;i<=(x/7-1);i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==5)
        {
            cout<<2;
            for(int i=1;i<=x/7;i++)cout<<8;
            cout<<endl;
        }
        else if(x%7==6)
        {
            cout<<6;
            for(int i=1;i<=x/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
