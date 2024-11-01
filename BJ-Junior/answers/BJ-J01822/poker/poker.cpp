#include <bits/stdc++.h>
using namespace std;
char s[55];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= 52; i++){
        cin >> s[i];
    }
    cout << 52 - n << endl;
    return 0;
}
