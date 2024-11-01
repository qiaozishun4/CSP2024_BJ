#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int dir[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
bool chk(int x)
{
    long long sum = 0;
    while(x > 0)
    {
        sum += dir[x%10];
        x /= 10;
    }

    if(sum == n) return 1;
    return 0;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {

        cin >> n;
        if(n == 1)
        {

            cout << -1 << endl;
            continue;
        }
        if(n % 7 == 0)
        {

            for(int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if((n-1) % 7 == 0)
        {
            cout << 10;
            for(int i = 1; i <= (n-1) / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }

        int f = 0;
        for(int i = 0; i <= 1000000000; i++)
        {
            if(chk(i))
            {
                cout << i << endl;
                f = 1;
                break;
            }
        }
        if(!f) cout << -1 << endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
