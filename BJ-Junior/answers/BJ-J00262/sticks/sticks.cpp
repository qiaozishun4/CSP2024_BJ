#include<iostream>
#include<math.h>
using namespace std;
int t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<-1<<'\n';
            continue;
        }
        if(n<=7)
        {
            for(int i=1;i<=9;i++)
                if(a[i]==n)
                {
                    cout<<i<<'\n';
                    break;
                }
            continue;
        }
        int x=ceil(double(n)/7),x2=n-(x-2)*7,s=900;
        for(int i=1;i<=9;i++)
            for(int j=0;j<=9;j++)
                if(a[i]+a[j]==x2)
                    s=min(s,i*10+j);
        cout<<s;
        for(int i=1;i<=x-2;i++)
            cout<<8;
        cout<<'\n';
    }
    return 0;
}
