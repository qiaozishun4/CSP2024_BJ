#include <bits/stdc++.h>
using namespace std;

string p[60];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = n;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i];
        for(int j=1; j<i; j++)
            if(p[j] == p[i])
            {
                cnt--;
                break;
            }
    }
    cout << max(0, 52-cnt) << endl;
    return 0;
}