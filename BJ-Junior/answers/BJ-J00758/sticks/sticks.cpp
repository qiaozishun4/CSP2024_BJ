#include<bits/stdc++.h>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, d, ans = 2e9;
void dfs(int step, int number){
    if(step == d){
        ans = min(ans, number);
        return ;
    }
    for(int i = 0; i <= 9; i++){
        if(i == 0 && step == 0) continue;
        if(number * 10 + i >= ans) return ;
        if(step + num[i] <= d) dfs(step + num[i], number * 10 + i);
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for(int l = 1; l <= t; l++){
        n = 0;
        ans = 2e9;
        cin >> n;
        if(n < 2){
            cout << "-1" << endl;
        }
        else if(n % 7 == 0){
            for(int i = 1; i <= n / 7; i++){
                cout << "8";
            }
            cout << endl;
        }
        else if(n % 7 == 1){
            cout << "10";
            for(int i = 1; i < n / 7; i++) cout << "8";
            cout << endl;
        }
        else{
            d = n % 7;
            if(n / 7 != 0) d += 7;
            dfs(0, 0);
            cout << ans;
            for(int i = 1; i < n / 7; i++) cout << "8";
            cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}