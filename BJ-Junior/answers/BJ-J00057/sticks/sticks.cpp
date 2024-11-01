#include <iostream>
using namespace std;

int use[10]={6,2,5,5,4,5,6,3,7,6};//实际上只需要考虑0 1 2 4 6 7 8

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else if(n==6)
        {
            cout<<6<<endl;
        }
        else if(n<6)
        {
            if(n==2)
            {
                cout<<1<<endl;
            }
            if(n==3) cout<<7<<endl;
            if(n==4) cout<<4<<endl;
            if(n==5) cout<<2<<endl;
        }
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<"\n";
        }

        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++) cout<<8;
            cout<<"\n";
        }
        else if(n%7==6)
        {
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++) cout<<8;
            cout<<"\n";
        }
        else if(n%7==5)
        {
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++) cout<<8;
            cout<<"\n";
        }
        else if(n%7==4)
        {
            cout<<20;
            for(int i=1;i<=(n-11)/7;i++) cout<<8;
            cout<<"\n";
        }
        else if(n%7==3)
        {
            if(n==10) cout<<22<<endl;
            else{
                cout<<200;
                for(int i=1;i<=(n-17)/7;i++) cout<<8;
                cout<<"\n";
            }

        }
        else if(n%7==2)
        {
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++) cout<<8;
            cout<<"\n";
        }




    }
    return 0;
}
