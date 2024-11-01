#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

const int r[]={6,2,5,-1,4,-1,6,3,7,6};

int T,n;

int main()
{
    fio("sticks");
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<-1;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++) cout<<8;
            continue;
        }
    }
}