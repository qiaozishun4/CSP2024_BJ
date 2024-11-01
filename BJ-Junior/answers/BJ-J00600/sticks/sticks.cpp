#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    int m;
    cin>>m;
    int u=0;
    if(m==1)
    {
        cout<<-1;continue;
    }
    if(m%7>1||m%7==0)
    {
        if(m%7==2)
        {
            u+=1;
            for(int j=0;j<m/7;j++)
            {
                u*=10;
                u+=8;
            }
        }
        if(m%7==3)
        {
            u+=7;
            for(int j=0;j<m/7;j++)
            {
                u*=10;
                u+=8;
            }
        }
        if(m%7==4)
        {
            u+=4;
            for(int j=0;j<m/7;j++)
            {
                u*=10;
                u+=8;
            }
        }
        if(m%7==5)
        {
            u+=2;
            for(int j=0;j<m/7;j++)
            {
                u*=10;
                u+=8;
            }
        }
        if(m%7==6)
        {
            u+=6;
            for(int j=0;j<m/7;j++)
            {
                u*=10;
                u+=8;
            }
        }
    }
    else
    {
        u+=12;
        for(int j=0;j<m/7-1;j++)
        {
            u*=10;
            u+=8;
        }
    }
    cout<<u<<endl;
}
return 0;
}