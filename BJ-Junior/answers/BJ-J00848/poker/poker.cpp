#include <iostream>
using namespace std;

string s[55];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n, cnt = 52;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        bool f = true;
        for (int j = 1; j < i; j++)
        {
            if (s[i] == s[j])  f = false;
        }
        if (f)  cnt--;
    }
    cout << cnt;
    return 0;
}