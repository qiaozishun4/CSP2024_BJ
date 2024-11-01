# include <rand>
# include <ctime>
# include <iostream>
using namespace std;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(NULL));
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        while (cin >> x) cout;
        while (q--)
        {
            cout << rand() % 2 << endl;
        }
    }
    return 0;
}
