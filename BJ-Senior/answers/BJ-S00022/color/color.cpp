#include <bits/stdc++.h>

using namespace std;

int dfs(int idx, int last, int sum, const int lim, const vector<int>&v, vector<vector<int>>&memo){
    // cout << idx << " " << last << endl;
    if (last != -1 && v[idx]==v[last]){
        sum += v[idx];
    }
    if (idx == lim){
        return sum;
    }

    int ret = INT_MIN;
    for (int i = idx + 1; i <= lim; i++){
        for (int j = idx; j < i; j++){
            if (memo[i][j] != -1){
                ret = max(memo[i][j], ret);
            }else{
                ret = max(dfs(i, j, sum, lim, v, memo), ret);
            }
        }
    }
    memo[idx][last] = max(ret, sum);
    return max(ret, sum);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	int queries;
	cin >> queries;
	for (int _ = 0; _ < queries; _++){
        int len;
        cin >> len;

        vector<vector<int>> memo(len + 5, vector<int>(len +5 , -1));
        vector<int>A(len);
        for (int i = 0; i < len; i++){
            cin >>A[i];
        }

        cout << dfs(0, -1, 0, len - 1, A, memo) << endl;

        /*
        vector<vector<pair<int, int>>>dp(len, vector<pair<int, int>>(len, {0, 0}));



        for (int i = 1; i < len; i++){
            for (int j = 0; j < i; j++){
                if (A[i] == A[j]){
                    dp[i][j].first += ? + A[i];
                    dp[i][j].second += ? + A[i];
                }
            }
        } */
	}


	return 0;
}
