#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0||n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=0;i<n/7;i++) cout<<8;
        }
        if(n%7==1)
        {
            cout<<16;
            for(int i=0;i<(n-8)/7;i++) cout<<8;
        }
        cout<<endl;
    }
}
