#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

const int f[30] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};

void SQ()
{
    int n;
    cin >> n;
    if (n <= 21)
    {
        cout << f[n] << endl;
        return ;
    }
    int m = (n + 1) % 7 + 13;
    int k = (n - m) / 7;
    cout << f[m];
    for (int i = 1; i <= k; i++)
        cout << 8;
    cout << endl;
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        SQ();
    }
    return 0;
}

