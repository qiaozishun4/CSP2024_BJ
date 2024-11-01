#include<bits/stdc++.h>
using namespace std;
long long t,n,a[11111111] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i = 10;i<=10000000;i++)
        a[i] = a[i/10]+a[i%10];
    cin>>t;
    while(t--)
    {
        long long cnt = 0;
        cin>>n;
        if(n%7 == 0 && n!=0)
        {
            for(int i = 1;i<=n/7;i++)
                cout<<8;
            cout<<endl;
        }
        else if((n-1)%7 == 0 && n!=1)
        {
            cout<<1<<0;
            for(int i = 2;i<=(n-1)/7;i++)
                cout<<8;
            cout<<endl;
        }
        else
        {
            for(int i = 1;i<=10000000;i++)
            if(a[i] == n)
            {
                cnt = i;
                break;
            }
            if(cnt)
            cout<<cnt<<endl;
            else
            cout<<-1<<endl;
        }
    }
    return 0;
}
