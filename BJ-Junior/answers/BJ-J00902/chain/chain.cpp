#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    srand(time(0));
    for (int i = 1; i <= t; i++)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for (int j = 1; j <= q; j++)
        {
            cout << rand() % 2 << endl;
        }
    }
    return 0;
}
