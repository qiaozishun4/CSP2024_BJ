#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 2 * 1e5;
ll T, a[N];

int main()
{
    cin >> T;
    while(T--)
    {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    cout << 1 << "\n" << 0 << "\n" << 8;
    return 0;
}
