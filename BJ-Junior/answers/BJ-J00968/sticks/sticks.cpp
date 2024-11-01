#include <bits/stdc++.h>
using namespace std;
long long T;
long long n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        int ans=0;
        cin>>n;
        if (n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        int b;
        b=n;
        while (b>0)
        {
            if (b>=7)
            {
                if (b==8)
                {
                    ans*=100;
                    ans+=61;
                    break;

                }
                b-=7;
                ans*=10;
                ans+=8;
            }
            else
            {
                if (b==6)
                {
                    ans*=10;
                    ans+=6;
                }
                if (b==5)
                {
                    ans*=10;
                    ans+=2;
                }
                if (b==4)
                {
                    ans*=10;
                    ans+=4;
                }
                if (b==3)
                {
                    ans*=10;
                    ans+=7;
                }
                if (b==2)
                {
                    ans*=10;
                    ans+=1;
                }
            }
        }
        while(ans>0)
        {
            cout<<ans%10;
            ans/=10;
        }
        cout<<endl;
    }
    return 0;
}
