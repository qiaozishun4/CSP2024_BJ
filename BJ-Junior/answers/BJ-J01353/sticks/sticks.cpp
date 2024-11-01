#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll T;
    cin >> T;
    while(T--)
    {
        ll n;
        cin >> n;
        if(n <= 1) cout << "-1" << endl;
        else if(n % 7 == 0)
        {
            for(ll i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else if(n % 7 == 1 && n != 1)
        {
            cout << "10";
            for(ll i = 1; i < n / 7; i++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else
        {
            for(ll i = 1; i <= pow(10,(n / 7 + 1)); i++)
            {
                ll x = i,sum = 0;
                while(x != 0)
                {
                    sum += a[x % 10];
                    x /= 10;
                }
                if(sum == n)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
