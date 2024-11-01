#include <iostream>
using namespace std;

const int s[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n<21)
        {
            cout<<s[n]<<endl;
            continue;
        }
        switch(n%7)
        {
        case 0:
            for(int i=0;i<n/7;i++)
                cout<<8;
            break;
        case 1:
            cout<<10;
            for(int i=1;i<n/7;i++)cout<<8;
            break;
        case 2:
            cout<<1;
            for(int i=1;i<=n/7;i++)
                cout<<8;
                break;
        case 3:
            cout<<200;
            for(int i=0;i<n/7-2;i++)
                cout<<8;
                break;
        case 4:
            cout<<20;
            for(int i=0;i<n/7-1;i++)
                cout<<8;
                break;
        case 5:
            cout<<2;
            for(int i=0;i<n/7;i++)
                cout<<8;
                break;
        case 6:
            cout<<6;
            for(int i=0;i<n/7;i++)
                cout<<8;
                break;

        }
        cout<<endl;
    }
    return 0;
}
