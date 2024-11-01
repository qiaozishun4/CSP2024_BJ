#include<bits/stdc++.h>
using namespace std;
int a[101]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t,x;
    cin >>t;
    while(t--)
    {
        cin >>n;
        if(n<=50) cout << a[n] << endl;
        else if(n%7==0)
        {
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-1)%7==0)
        {
            cout << 10;
            n=n-8;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-2)%7==0)
        {
            cout << 1;
            n=n-2;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-3)%7==0)
        {
            cout << 200;
            n=n-17;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-4)%7==0)
        {
            cout << 20;
            n=n-11;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-5)%7==0)
        {
            cout << 2;
            n=n-5;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout <<endl;
        }
        else if((n-6)%7==0)
        {
            cout << 6;
            n=n-6;
            x=n/7;
            for(int i=1;i<=x;i++) cout << 8;
            cout << endl;
        }
        else cout <<"-1\n";
    }
    return 0;
}
