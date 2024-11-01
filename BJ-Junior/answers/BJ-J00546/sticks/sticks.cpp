#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[60]={0,-1,1,7,4,2,6,8,10,42,22,20,60,80,88,606,400,200,208,800,808,888,4000};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }
        else cout<<a[n]<<endl;
    }
}
