# include <iostream>
# include <map>
# include <string>
using namespace std;
map<string, int> a;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string x;
    int cnt = 52;
    for (int i = 1; i <= n; i ++)
    {
        cin >> x;
        if (a[x] == 0) cnt--;
        a[x]++;
    }
    cout << cnt;
    return 0;
}
