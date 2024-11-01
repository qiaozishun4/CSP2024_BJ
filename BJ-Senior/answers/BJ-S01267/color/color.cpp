#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N], id[N];

int dp[110][2][110];

bitset<20> bs;

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int maxn = 0;
        for(int i = 1; i <= n; i++){
			cin >> a[i];
			maxn = max(maxn, a[i]);
		}
		if(maxn <= 10 && n > 20){
			//cout << 1 << endl;
            int ans = 0;
			for(int i = 0; i < (1 << maxn); i++){
                bs = i;
                int last1 = 0, last2 = 0, sum = 0;
                for(int j = 1; j <= n; j++){
                    if(bs[a[j] - 1] == 1){
                        if(a[j] == a[last1]) sum = sum + a[j];
                        last1 = j;
                    }else{
                        if(a[j] == a[last2]) sum = sum + a[j];
                        last2 = j;
                    }
                }
                ans = max(ans, sum);
            }
            cout << ans << endl;
            continue;
		}
        int ans = 0;
        for(int i = 0; i < (1 << n); i++){
            bs = i;
            int last1 = 0, last2 = 0, sum = 0;
            for(int j = 0; j < n; j++){
                if(bs[j] == 0){
                    if(a[j + 1] == a[last1]) sum += a[j + 1];
                    last1 = j + 1;
                }else{
                    if(a[j + 1] == a[last2]) sum += a[j + 1];
                    last2 = j + 1;
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
}
