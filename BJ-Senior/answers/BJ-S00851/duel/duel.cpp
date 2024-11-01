#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];

multiset<int> s;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]), s.insert(a[i]);
    stable_sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (s.upper_bound(a[i]) != s.end()){
            //printf("find %d for id = %d\n", *s.upper_bound(a[i]), i);
            ans++;
            s.erase(s.upper_bound(a[i]));
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
