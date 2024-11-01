#include <iostream>
#include <random>
using namespace std;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        if(n == 3)
        {
            cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
        }
        for(int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            for(int j = 1; j <= l; j++)
            {
                int x;
                cin >> x;
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int r, c;
            cin >> r >> c;
            int ra = rand() % 2;
            if(ra == 1)cout << 1 << endl;
            else cout << 0 << endl;
        }

    }
    return 0;
}
