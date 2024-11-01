#include<bits/stdc++.h>
using namespace std;
bool flag = 1;
int k, n, cnt, num, a[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> k;
    while(k--)
    {
        cin >> n;
        for(int i = 0; i < 99999999; i++)
        {
            cnt = 0;
            num = i;
            while(num)
            {
                cnt += a[num % 10];
                num /= 10;
            }
            if(cnt == n)
            {
                cout << i << '\n';
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << -1 << '\n';
    }
    return 0;
}
