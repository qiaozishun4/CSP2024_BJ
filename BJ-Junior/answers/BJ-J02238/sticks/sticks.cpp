#include<iostream>
using namespace std;
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++)cout<<8;
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}
