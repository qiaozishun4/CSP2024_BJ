#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n<2)
        {
            cout << -1 << endl;
            continue;
        }
        int p=(n+6)/7;
        if(n%7==0)
        {
            for(int i=1; i<=p; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(n%7==1)
        {
            cout << 10;
            for(int i=1; i<=p-2; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(n%7==2)
        {
            cout << 1;
            for(int i=1; i<=p-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(n%7==3)
        {
            if(p>=3)
            {
                cout << 200;
                for(int i=1; i<=p-3; i++)
                    cout << 8;
                cout <<endl;
            }
            else if(p==2)
            {
                cout << 22;
            }
            else
                cout << 7 << endl;
            continue;
        }
        if(n%7==4)
        {
            if(p>=2)
            {
                cout << 20;
                for(int i=1; i<=p-2; i++)
                    cout << 8;
                cout << endl;
            }
            else
                cout << 4 << endl;
            continue;
        }
        if(n%7==5)
        {
            cout << 2;
            for(int i=1; i<=p-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(n%7==6)
        {
            cout << 6;
            for(int i=1; i<=p-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
    }
    return 0;
}