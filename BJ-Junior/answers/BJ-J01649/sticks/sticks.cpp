#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll cnt[]={6,2,5,5,4,5,6,3,7,6},t,n,f[100010];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    f[6]=6;f[5]=2;f[4]=4;f[2]=1;f[3]=7;f[7]=8;
    for (ll i=0;i<100010;i++)
    {
        bool flag=1;
        ll x;
        vector<ll> tmp;
        if (f[i])
        {
            flag=1;
        }
        else
        {
            if (i>6)
            {
                x=f[i-6]*10;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
            if (i>2)
            {
                x=f[i-2]*10+1;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
            if (i>5)
            {
                x=f[i-5]*10+2;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
            if (i>4)
            {
                x=f[i-4]*10+4;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
            if (i>3)
            {
                x=f[i-3]*10+7;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
            if (i>7)
            {
                x=f[i-7]*10+8;
                if (x)
                {
                    tmp.push_back(x);
                    flag=0;
                }
            }
        }
        if (!flag)
            f[i]=*min_element(tmp.begin(),tmp.end());
    }
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (f[n])
            cout<<f[n]<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
