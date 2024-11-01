#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool flag[200010];
int score(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] == a[j] && flag[i] == flag[j]) cnt += a[i];
        }
    }
    return cnt;
}
void f(int i){
    int cur = 0;
    while(i){
        flag[++cur] = i % 2;
        i /= 2;
    }
    return ;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++){
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < (1 << n); i++){
            f(i);
            ans = max(ans, score(n));
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}