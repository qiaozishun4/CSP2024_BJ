#include <bits/stdc++.h>

using namespace std;
long long T, n, a[200005], dp[200005], t[1000005], lin[200005];
//对于每一组数，它内部必须同为同一种颜色时才会得分。
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        memset(lin, 0, sizeof(lin));
        memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        if(a[1] == a[2]) lin[1] = a[1];
        for(int i = 2;i <= n-1;i++){
                if(a[i] == a[i+1]){
                    lin[i] = lin[i-1] + a[i];
                }
                else lin[i] = lin[i-1];
        }
        //cout << lin[6] << " ";

        //相邻的同种数字必然得分。
        for(int i = 1;i <= n;i++){
            if(t[a[i]] == 0) t[a[i]] = i,dp[i] = dp[i-1];
            else{
                dp[i] = max(dp[i-1], max(dp[t[a[i]]+1], max(dp[t[a[i]]], dp[t[a[i]]-1])) + a[i] + lin[i-1]-lin[t[a[i]]]);
                t[a[i]] = i;
            }
            //cout << dp[i] << " ";
        }
        cout << dp[n] << endl;

    }
    return 0;
    //1 7 79 80 79 79 79 77 80
}

