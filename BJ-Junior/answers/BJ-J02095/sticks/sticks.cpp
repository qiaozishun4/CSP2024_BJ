#include<bits/stdc++.h>
using namespace std;

int T;
int sy[105];
int xy[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for(int i = 0; i <= 100; i++)
    {
        sy[i] = -1;
    }
    for(int i = 0; i <= 5000000; i++)
    {
        int tmp = i, cnt = 0;
        while(tmp > 0)
        {
            cnt += xy[tmp % 10];
            tmp /= 10;
        }
        if(sy[cnt] == -1)
        {
            sy[cnt] = i;
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n <= 50)
        {
            cout << sy[n] << endl;
        }
        else
        {
            for(int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
