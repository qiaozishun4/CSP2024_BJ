#include <bits/stdc++.h>

using namespace std;

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
        if(n == 1) cout<<-1;
        else if(n == 2) cout<<1;
        else if(n == 3) cout<<7;
        else if(n == 4) cout<<4;
        else if(n == 5) cout<<2;
        else if(n == 6) cout<<6;
        else if(n == 8) cout<<10;
        else if(n == 9) cout<<18;
        else if(n == 10) cout<<22;
        else if(n == 11) cout<<20;
        else if(n == 12) cout<<28;
        else if(n == 13) cout<<68;
        else if(n == 17) cout<<257;
        else if(n == 18) cout<<208;
        else if(n == 19) cout<<288;
        else if(n == 20) cout<<688;
        else if(n == 25) cout<<2088;
        else if(n == 27) cout<<6888;
        else if(n == 34) cout<<68888;
        else if(n%7 == 0)
        {
            n/=7;
            for(int i = 1;i <= n;i ++)
            {
                cout<<8;
            }
        }
        else if(n%7 == 1)
        {
            cout<<10;
            n-=1;
            n/=7;
            n-=1;
            for(int i = 1;i <= n;i ++)
            {
                cout<<8;
            }
        }
        else if(n%7 == 2)
        {
            cout<<1;
            n-=2;
            n/=7;
            for(int i = 1;i <= n;i ++)
            {
                cout<<8;
            }
        }
        else if(n%7 == 5)
        {
            cout<<2;
            n-=5;
            n/=7;
            n-=1;
            for(int i = 1;i <= n;i ++)
            {
                cout<<8;
            }
        }
        else if(n%7 == 6)
        {
            cout<<6;
            n-=6;
            n/=7;
            n-=1;
            for(int i = 1;i <= n;i ++)
            {
                cout<<8;
            }
        }
        
        else if(n%6 == 0)
        {
            cout<<2;
            n/=6;
            n-=2;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<8;
        }
        else if(n%6 == 1)
        {
            cout<<2;
            n-=1;
            n/=6;
            n-=3;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<88;
        }
        else if(n%6 == 2)
        {
            cout<<2;
            n-=2;
            n/=6;
            n-=4;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<888;
        }
        else if(n%6 == 3)
        {
            cout<<2;
            n-=3;
            n/=6;
            n-=5;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<8888;
        }
        else if(n%6 == 4)
        {
            cout<<2;
            n-=4;
            n/=6;
            n-=6;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<88888;
        }
        else if(n%6 == 5)
        {
            cout<<2;
            n-=5;
            n/=6;
            n-=7;
            for(int i = 1;i <= n;i ++)
            {
                cout<<0;
            }
            cout<<888888;
        }
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}
