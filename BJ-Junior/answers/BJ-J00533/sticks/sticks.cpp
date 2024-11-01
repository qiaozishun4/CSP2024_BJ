#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
int n,t,minn;
int w[110];

void dfs(int sum,int num)
{
    if(sum>n)
    {
        return;
    }
    if(num>minn)
    {
        return;
    }
    if(sum==n)
    {
        minn=num;
    }
    for(int i=0;i<=9;i++)
    {
        if(num*10+i==0)
        {
            continue;
        }
        dfs(sum+w[i],num*10+i);
    }
    return;
}

signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    w[0]=6;
    w[1]=2;
    w[2]=5;
    w[3]=5;
    w[4]=4;
    w[5]=5;
    w[6]=6;
    w[7]=3;
    w[8]=7;
    w[9]=6;
    while(t--)
    {
        cin>>n;
        minn=1e9;
        if(n%7==0&&n!=0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1&&n!=1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==2&&n!=2)
        {

            cout<<1;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3&&n!=3&&n!=10)
        {

            cout<<200;
            for(int i=1;i<=n/7-2;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==4&&n!=4)
        {

            cout<<20;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==5&&n!=5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6&&n!=6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        dfs(0,0);
        if(minn!=1e9)
        {
            cout<<minn<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
