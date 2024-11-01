#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int read(){
    int res = 0, flag = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            flag = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res * flag;
}
int a[MAXN];
priority_queue <int, vector <int>, greater <int> > q;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    int ans = n;
    for (int i = 1; i <= n; i++){
        if (!q.empty() && q.top() < a[i]){
            ans--;
            q.pop();
        }
        q.push(a[i]);
    }
    cout << ans << endl;
    return 0;
}