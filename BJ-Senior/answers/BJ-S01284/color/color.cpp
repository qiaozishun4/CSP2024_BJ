#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 11;
int a[MAXN];
int v[MAXN];
int n;
long long sum;
void dfs(int cur){
    if(cur == n + 1){
        int ans;
        long long summ = 0;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                if(v[j] == v[i]){
                    ans = j;
                }
            }
            if(a[ans] == a[i]){
                summ += a[i];
            }
            ans = 0;
        }
        sum = max(sum, summ);
        return;
    }
    for(int i = 1; i <= 2; ++i){
        v[cur] = i;
        dfs(cur + 1);
    }
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        dfs(1);
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
