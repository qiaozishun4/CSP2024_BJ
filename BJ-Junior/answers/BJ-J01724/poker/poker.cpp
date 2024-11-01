#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;
int n;
string s[N];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        bool flag = true;
        getline(cin, s[i]);
        for(int j = 1; j <= i - 1; j++) {
            if(s[j] == s[i]) {
                flag = false;
            }
        }
        if(flag) ans++;
    }
    cout << 52 - ans << '\n';
    return 0;
}
