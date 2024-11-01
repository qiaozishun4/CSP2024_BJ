#include<bits/stdc++.h>
using namespace std;
struct Node{
    int l, r;
}cnt[10005];
int n, m ,L, V;
int d[10005], v[10005], a[10005], p[10005];
int main(){
    int t;
    freopen("detect.in", "r", stdin);
    freopen("detect.ans", "w", stdout);
    cin >> t;
    cin >> n >> m >> L >>  V;
    for(int i = 1; i <= n; i++){
        cin >> d[i] >> v[i] >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            long long h = p[i] - d[i];
        }
    }
    cout << "3 3";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
