#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

ll type[60][60];
string a;
ll n, ans = 52, l = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ll x = a[0] - '0', y = a[1] - '0';
        if (type[x][y] == 0)
        {
            type[x][y] = 1;
            l++;
        }
    }
    cout << 52 - l;
    return 0;
}
