#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string ans;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n==2)
        {
            cout << 1 << endl;
            continue;
        }
        if(n==3)
        {
            cout << 7 << endl;
            continue;
        }
        if(n==4)
        {
            cout << 4 << endl;
            continue;
        }
        if(n==5)
        {
            cout << 2 << endl;
            continue;
        }
        if(n==6)
        {
            cout << 6 << endl;
            continue;
        }
        if(n==10)
        {
            cout << 23 << endl;
            continue;
        }
        if(n==11)
        {
            cout << 20 << endl;
            continue;
        }
        if(n==12)
        {
            cout << 28 << endl;
            continue;
        }
        if(n==13)
        {
            cout << 68 << endl;
            continue;
        }

        if(n==17)
        {
            cout << 206 << endl;
            continue;
        }
        if(n==18)
        {
            cout << 208 << endl;
            continue;
        }
        if(n==19)
        {
            cout << 288 << endl;
            continue;
        }
        if(n==20)
        {
            cout << 688 << endl;
            continue;
        }
        if(n==24)
        {
            cout << 2008 << endl;
            continue;
        }
        if(n==25)
        {
            cout << 2088 << endl;
            continue;
        }
        if(n==26)
        {
            cout << 2888 << endl;
            continue;
        }
        if(n%7==0)
        {
            k=n/7;
            for(int i=1;i<=k;i++)
            {
                ans+='8';
            }
            cout << ans << endl;
        }
        if(n%7==1)
        {
            k=n/7;
            ans="10";
            for(int i=1;i<=k-1;i++)
            {
                ans+='8';
            }
            cout << ans << endl;
        }
        if(n%7==2)
        {
            k=n/7;
            ans="1";
            for(int i=1;i<=k;i++)
            {
                ans+='8';
            }
            cout << ans << endl;
        }
    }
    return 0;
}
