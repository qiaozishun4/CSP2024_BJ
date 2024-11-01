#include <iostream>
#include <cstring>
using namespace std;
int q;
int w[8] = {0, 6, 2, 5, 4, 6, 3, 7};
int p[8] = {0, 0, 1, 2, 4, 6, 7, 8};
int ans[50005], a[50005];
int minn = 1e9;
void f(int n, int cnt)
{
    if(n < 0) return;
    if(cnt >= minn && n != 0) return;
    if(n == 0)
    {
        if(cnt < minn)
        {
            for(int i = 1; i <= cnt;i++)
            {
                ans[i] = a[i];
            }
            minn = cnt;
        }
        else if(cnt == minn)
        {
            bool e = 0;
            for(int i = 1; i <= minn;i++)
            {
                if(ans[i] > a[i])
                {
                    e = 1;
                    break;
                }
                else if(ans[i] < a[i])
                {
                    break;
                }
            }
            if(e == true)
            {
                for(int i = 1; i <= cnt;i++)
                {
                    ans[i] = a[i];
                }
            }
        }
        return;
    }
    for(int i = 1; i <= 7;i++)
    {
        if(n - w[i] >= 0)
        {
            a[cnt + 1] = p[i];
            f(n - w[i], cnt + 1);
            a[cnt + 1] = 0;
        }
    }
    return;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        minn = 1e9;
        cin >> q;
        if(q % 7 == 0)
        {
            int u = q / 7;
            for(int i = 1; i <= u;i++) cout << "8";
            cout << endl;
            continue;
        }
        else if((q - 1) % 7 == 0)
        {
            int u = (q - 1) / 7;
            cout << "10";
            for(int i = 1; i < u;i++) cout << "8";
            cout << endl;
            continue;
        }
        for(int i = 2; i <= 7;i++)
        {
            a[1] = p[i];
            f(q - w[i], 1);
        }
        if(minn == 1e9)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i <= minn;i++) cout << ans[i];
        cout << endl;
    }
    return 0;
}
