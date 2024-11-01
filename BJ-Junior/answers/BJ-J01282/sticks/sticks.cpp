#include<iostream>
#include<queue>
using namespace std;

int cnt[7] = {0, -1, 1, 7, 4, 2, 6};
int mp[7] = {8, 10, 18, 23, 20, 28, 68};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n < 7)
            cout << cnt[n] << endl;
        else
        {
            cout << mp[n % 7];
            for(int i = 1; i <= n / 7 - 1; i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
