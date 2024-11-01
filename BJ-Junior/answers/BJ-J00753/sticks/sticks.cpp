#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10;
int a[N + 5] = {1,5,2,2,3,2,1,4,0,1};
int n;

signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        int len = ceil(1.0 * n / 7),t = len * 7 - n;
        for(int i = 1;i <= len;i++)
        {
            if(t == 0)
            {
                cout << 8;
                continue;
            }
            if(i != 1 && i != len)
            {
                cout << 0;
                t--;
                continue;
            }
            if(len == 1)
            {
                for(int j = 1;j <= 9;j++)
                {
                    if(a[j] == t)
                    {
                        cout << j;
                        break;
                    }
                }
                break;
            }
            else if(i == 1)
            {
                for(int j = 1;j <= 9;j++)
                {
                    if(a[j] <= t)
                    {
                        t -= a[j];
                        cout << j;
                        break;
                    }
                }

            }
            else
            {
                for(int j = 0;j <= 9;j++)
                {
                    if(a[j] == t)
                    {
                        cout << j;
                        break;
                    }
                }
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
