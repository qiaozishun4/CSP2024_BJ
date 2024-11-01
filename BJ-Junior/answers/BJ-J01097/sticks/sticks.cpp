#include<bits/stdc++.h>
using namespace std;
int n[55];
int t, maxx;
int sticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> dp[100010];
int cmp(vector<int> a, vector<int> b)
{
    if(a.size() == 0) return 0;
    if(a.size() > b.size()) return 0;
    else if(a.size() < b.size()) return 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]) return 1;
        if(a[i] > b[i]) return 0;
    }
    return -1;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n[i];
        maxx = max(maxx, n[i]);
    }
    for(int i = 1; i <= maxx; i++){
        for(int j = 0; j <= 9; j++){
            if(sticks[j] <= i){
                if(dp[i - sticks[j]].size() == 0 && i - sticks[j] != 0) continue;
                if(dp[i - sticks[j]].size() == 0 && j == 0) continue;
                vector<int> tmp = dp[i - sticks[j]];
                tmp.push_back(j);
                if(cmp(dp[i], tmp) == 0){
                    dp[i] = tmp;
                }
            }
        }
    }
    for(int i = 1; i <= t; i++){
        if(dp[n[i]].size() == 0) cout << -1 << endl;
        else{
            for(int j = 0; j < dp[n[i]].size(); j++){
                cout << dp[n[i]][j];
            }
            cout << endl;
        }
    }
    return 0;
}
