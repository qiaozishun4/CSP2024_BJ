#include<bits/stdc++.h>
using namespace std;
int n;
int x;
string s;
int a[10]={-1,-1,1,7,4,2,6,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x<=7)
        {
            cout<<a[x]<<"\n";
            continue;
        }
        if(x==10)
        {
            cout<<22<<"\n";
            continue;
        }
        int w=x/7;
        if(x%7) w++;
        if(x%7==0)
            for(int i=1;i<=w;i++)
                cout<<8;
        else if(x%7==1)
        {
            cout<<10;
            for(int i=1;i<=w-2;i++)
                cout<<8;
        }
        else if(x%7==2)
        {
            cout<<1;
            for(int i=1;i<=w-1;i++)
                cout<<8;
        }
        else if(x%7==3)
        {
            cout<<200;
            for(int i=1;i<=w-3;i++)
                cout<<8;
        }
        else if(x%7==4)
        {
            cout<<20;
            for(int i=1;i<=w-2;i++)
                cout<<8;
        }
        else if(x%7==5)
        {
            cout<<2;
            for(int i=1;i<=w-1;i++)
                cout<<8;
        }
        else
        {
            cout<<6;
            for(int i=1;i<=w-1;i++)
                cout<<8;
        }
        cout<<"\n";
    }
    return 0;
}
/*
0
1 10
2 1
3 22
4 20
5 2
6 6
*/
