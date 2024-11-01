
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << -1 << endl;
        }
        else if(n==2)
        {
            cout << 1 << endl;
        }
        else if(n==3)
        {
            cout << 7 << endl;
        }
        else if(n==4)
        {
            cout << 4 <<  endl;
        }
        else if(n==5)
        {
            cout << 2 << endl;
        }
        else if(n==6)
        {
            cout << 6 << endl;
        }
        else if(n%7==0)
        {
            for(int i=7;i<=n;i+=7)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==1)
        {
            cout << 10;
            for(int i=15;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==2)
        {
            cout << 18;
            for(int i=16;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==3)
        {
            cout << 22;
            for(int i=17;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==4)
        {
            cout << 20;
            for(int i=18;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==5)
        {
            cout << 60;
            for(int i=19;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==6)
        {
            cout << 68;
            for(int i=20;i<=n;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
