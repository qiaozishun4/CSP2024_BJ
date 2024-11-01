#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map<string,bool> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans = 52;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        if (m[s] == false)
        {
            m[s] = true;
            ans--;
        }
    }
    cout << ans;
    return 0;
}
