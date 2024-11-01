#include<bits/stdc++.h>
using namespace std;
struct st
{
    int sz;
    int d;
}s[10];
bool cmp(st a,st b)
{
    if(a.d==b.d)return a.sz<b.sz;
    return a.d<b.d;
}
int main()
{
    int t,a[10]={6,2,5,5,4,5,6,3,7,6};
    for(int i=0;i<10;i++)
    {
        s[i].sz=i;
        s[i].d=a[i];
    }
    cin>>t;
    while(t>0)
    {
        t--;
        int n;
        cin>>n;
        if(n==1)
        {

            cout<<-1;
            continue;
        }
        else if(n<=7)
        {
            if(n==2)cout<<1;
            if(n==3)cout<<7;
            if(n==4)cout<<4;
            if(n==5)cout<<3;
            if(n==6)cout<<6;
            if(n==7)cout<<8;
            continue;

        }
        int k=n%7,mins=100000,mj;
        for(int j=0;j<10;j++)
        {
            if(s[j].d>=k&&s[j].sz<mj&&s[j].sz!=0)
            {
                mins=s[j].sz;
                mj=j;
            }
        }
        cout<<mins;
        s[mj].sz=-1;
        mins=100000;
        for(int i=2;i<=ceil(n*1.0/3);i++)
        {
            for(int j=0;i<10;j++)
            {
                if(s[j].d>=k&&s[j].sz<mj&&s[j].sz!=-1)
                {
                    mins=s[j].sz;
                    mj=j;
                }
            }
            cout<<mins;
            s[mj].sz=-1;
        }
        cout<<endl;
        for(int i=0;i<10;i++)
        {
            s[i].sz=i;
            s[i].d=a[i];
        }
    }
    return 0;
}
