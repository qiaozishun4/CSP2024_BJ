#include <bits/stdc++.h>
using namespace std;
long long T, n, ans, sum[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string num[] = {"-1", "-1", "1", "7", "4", "2", "0", "8"};
string s_ans;
void dfs(long long shengyu, long long cnt, string s_cnt){
    //摆完了
    if (shengyu == 0){
        if (cnt < ans)
            s_ans = s_cnt;
        ans = min(ans, cnt);
        return;
    }
    //最优性剪枝
    if (cnt >= ans) return;

    for (int i = 2; i <= 7; i++){
        if (i > shengyu) break;
        dfs(shengyu - i, cnt + 1, s_cnt + num[i]);
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--){
        ans = (long long)2e18;
        s_ans = "-1";
        cin >> n;
        if (n <= 1){
            cout << "-1\n";
            continue;
        }
        if (n % 7 == 0){
            for (long long i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
            continue;
        }
        if ((n - 1) % 7 == 0){
            cout << "10";
            n -= 8;
            for (long long i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
            continue;
        }
//        if (n <= 7){
//            cout << num[n] << "\n";
//            continue;
//        }
        for (int i = 1; i <= 9; i++){
            dfs(n - sum[i], 1, to_string(i));
        }
        cout << s_ans << "\n";
    }
    return 0;
}
