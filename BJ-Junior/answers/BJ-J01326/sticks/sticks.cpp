#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[10]={0,-1,1,7,4,5,6,8,0,0};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<=7)cout << a[n] << endl;
        else
        {
        if(n%7==0)
        {
            for(int i=1;i*7<=n;i++)cout << 8;
            cout << endl;
        }
        if(n%7==1)
        {
            cout << 10;
            for(int i=1;i*7<=n-7;i++)cout << 8;
            cout << endl;
        }
        if(n%7==2)
        {
            cout << 1;
            for(int i=1;i*7<=n;i++)cout << 8;
            cout << endl;
        }
        if(n%7==3)
        {
            cout << 22;
            for(int i=1;i*7<=n-7;i++)cout << 8;
            cout << endl;
        }
        if(n%7==4)
        {
            cout << 20;
            for(int i=1;i*7<=n-7;i++)cout << 8;
            cout << endl;
        }
        if(n%7==5)
        {
            cout << 28;
            for(int i=1;i*7<=n-7;i++)cout << 8;
            cout << endl;
        }
        if(n%7==6)
        {
            cout << 6;
            for(int i=1;i*7<=n;i++)cout << 8;
            cout << endl;
        }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}