#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<int,bool> m;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        string a;
        cin >> a;
        int x = int(a[0]) * 10000 + int(a[1]);
        if (m[x] == false)
        {
            m[x] = true;
            cnt++;
        }
    }
    cout << 52 - cnt;
    return 0;
}
